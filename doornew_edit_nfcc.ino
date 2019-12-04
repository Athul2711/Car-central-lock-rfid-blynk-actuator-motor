//CODE BY ATHULKRISHNA>S
//code updated



#include <Blynk.h>

#include <ESP8266mDNS.h>  // For OTA w/ ESP8266
#include <WiFiUdp.h>  // For OTA
#include <ArduinoOTA.h>  // For OTA
//#define BLYNK_PRINT Serial
#include <TimeLib.h>
#include <SPI.h>
#include <MFRC522.h>
#include <SimpleTimer.h> 

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define SS_PIN D4
#define RST_PIN D3
#define relaypina D2
#define relaypinb D0

#define sensorpin D1


int atk = LOW;


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "9Rdi-z_bar9kjZ-PZSgKkCG_fxI8PW4F";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "hlo1";
char pass[] = "1231231234";
char ACCESS_KEY[] = "09 97 3D 59";
char ACCESS_CARD[] = "C7 46 62 40";



BlynkTimer timer;


MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.


WidgetTerminal terminal(V40);


WidgetLED led(V10);

WidgetLCD lcd(V100);


void autounlock(){
  int valuaa = digitalRead(sensorpin);

  delay(1000);
  int valuab = digitalRead(sensorpin);
  if (valuaa != valuab && valuab == HIGH && atk == LOW){
    terminal.println("LOCKED via autounlock");
    terminal.flush();   

    digitalWrite(relaypina, LOW);
    digitalWrite(relaypinb, HIGH);
    delay(200);
    digitalWrite(relaypina, HIGH); 
    digitalWrite(relaypinb, HIGH);
  }
  if (valuab != valuaa && valuab == LOW && atk == LOW){
    terminal.println("UNLOCKED via autounlock");
    terminal.flush();   

    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, LOW);
    delay(200);
    digitalWrite(relaypina, HIGH); 
    digitalWrite(relaypinb, HIGH);


  }

  
}
void lock(){
  int aaab = digitalRead(D1);

  
  
  if (aaab == HIGH){
    
    
    lcd.print(1, 0, "STATUS:LOCKED..");
  } else {
    lcd.print(1, 0, "STATUS:UNLOCKED");
  }

  
    
}

void sendvalue()
{
  int aaab = digitalRead(sensorpin);
  Blynk.virtualWrite(V12,aaab);

  if (WiFi.status() == WL_CONNECTED) {
    long rssi = WiFi.RSSI();
    lcd.print(2, 1, "Signal:");
    lcd.print(8, 1, rssi);

  }
 

  mfrc522.PCD_Init();   // Initiate MFRC522

    


}










BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue = HIGH) {
    digitalWrite(relaypina, LOW);
    digitalWrite(relaypinb, HIGH);
    atk = HIGH;
    delay(200);
    digitalWrite(relaypina, HIGH); 
    digitalWrite(relaypinb, HIGH);
    terminal.println("LOCKED");
    lcd.clear();
    lcd.print(1, 0, "STATUS:LOCKED");
    terminal.flush();  
    delay(1800);
    atk = LOW; 
  } else {
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
  }
  

}


void repeatMe() {
  int but = digitalRead(sensorpin);
  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on terminal monitor
  terminal.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     terminal.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     terminal.print(mfrc522.uid.uidByte[i], HEX);
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == ACCESS_KEY && but == LOW) //change here the UID of the card/cards that you want to give access
  {
    terminal.println("Authorized access via rfid LOCKED");
    digitalWrite(relaypina, LOW);
    digitalWrite(relaypinb, HIGH);
    atk = HIGH;
    delay(200);
    digitalWrite(relaypina, HIGH); 
    digitalWrite(relaypinb, HIGH);
    delay(1800);
    atk = LOW;
  }
  if (content.substring(1) == ACCESS_KEY && but == HIGH) //change here the UID of the card/cards that you want to give access
  {
    terminal.println("Authorized access via rfid UNLOCKED");
    terminal.flush();   
    atk = HIGH;
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, LOW);
    delay(200);
    digitalWrite(relaypina, HIGH); 
    digitalWrite(relaypinb, HIGH);
    delay(1800);
    atk = LOW;
  }



  if (content.substring(1) == ACCESS_CARD && but == HIGH) //change here the UID of the card/cards that you want to give access
  {
    terminal.println("Authorized access via rfid UNLOCKED");
    terminal.flush();   
    atk = HIGH;
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, LOW);
    delay(200);
    digitalWrite(relaypina, HIGH); 
    digitalWrite(relaypinb, HIGH);
    delay(1800);
    atk = LOW;
  }

  if (content.substring(1) == ACCESS_CARD && but == LOW) //change here the UID of the card/cards that you want to give access
  {
    terminal.println("Authorized access via rfid LOCKED");
    digitalWrite(relaypina, LOW);
     atk = HIGH;
    digitalWrite(relaypinb, HIGH);
    delay(200);
    digitalWrite(relaypina, HIGH); 
    digitalWrite(relaypinb, HIGH);
    delay(1800);
    atk = LOW;
  }

 
}
  

    










BLYNK_WRITE(V2)
{
  int pinValuea = param.asInt(); // assigning incoming value from pin V2 to a variable
  if (pinValuea = HIGH) {
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, LOW);
    atk = HIGH;
    
    delay(200);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
    terminal.println("UNLOCKED");
    lcd.clear();
    
    lcd.print(1, 0, "STATUS:UNLOCKED");
    terminal.flush();  
    delay(1800);
    atk = LOW;
   
  } else {
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
  }
  

}
void setup()
{
  WiFi.begin(ssid, pass);
  pinMode(relaypina, OUTPUT);
  pinMode(relaypinb, OUTPUT);
  pinMode(sensorpin, INPUT);
  digitalWrite(relaypina, HIGH);
  digitalWrite(relaypinb, HIGH);
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  lcd.clear();
  terminal.clear();
  terminal.println("Put your card to the reader...");
  



  ArduinoOTA.setHostname("AThulKrishna.s_OTA_UPDATE");  // For OTA - Use your own device identifying name
  ArduinoOTA.begin();  // For OTA






  timer.setInterval(10, repeatMe);






  timer.setInterval(2000, sendvalue);

  timer.setInterval(1000, autounlock);
  timer.setInterval(2000, lock);

  led.on();
















}




void loop()
{
  ArduinoOTA.handle();
  if (WiFi.status() == WL_CONNECTED){
    

    Blynk.run();
  }
  timer.run();
}
