//CODE BY ATHULKRISHNA>S
//



#include <Blynk.h>


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





// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "-hPnVq5cjXpbpbLvKB_QKAA8LPv0y0jS";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "hlo1";
char pass[] = "1231231234";
#define ACCESS_DELAY 2000
#define DENIED_DELAY 1000

BlynkTimer timer;


MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.


WidgetTerminal terminal(V40);




WidgetLCD lcd(V100);









void sendvalue()
{
  int aab = digitalRead(sensorpin);
  Blynk.virtualWrite(V12,aab);

}




BLYNK_WRITE(V13)
{ int avala = digitalRead(sensorpin);
  int pinValuez = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValuez == HIGH && avala == LOW ) {
    
    Blynk.virtualWrite(V30,1);
    delay(10);
    Blynk.virtualWrite(V30,0);
    
  }

  if (pinValuez == HIGH && avala == HIGH ) {
    
    Blynk.virtualWrite(V31,1);
    delay(10);
    Blynk.virtualWrite(V31,0);
    
  }


}






BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue = HIGH) {
    digitalWrite(relaypina, LOW);
    digitalWrite(relaypinb, HIGH);
    delay(200);
    digitalWrite(relaypina, HIGH); 
    digitalWrite(relaypinb, HIGH);
    terminal.println("LOCKED");
    lcd.print(4, 0, "STATUS:LOCKED")
    terminal.flush();   
  } else {
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
  }
  

}



void wifisig() {

  if (WiFi.status() = WL_CONNECTED) {
    long rssi = WiFi.RSSI();
    Serial.print("RSSI:");
    
    lcd.print(2, 1, "Signal:")
    lcd.print(8, 1, rssi);
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
     Terminal.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Terminal.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "C5 94 7C 69" && but == LOW) //change here the UID of the card/cards that you want to give access
  {
    terminal.println("Authorized access via rfid LOCKED");
    digitalWrite(relaypina, LOW);
    digitalWrite(relaypinb, HIGH);
    delay(200);
    digitalWrite(relaypina, HIGH); 
    digitalWrite(relaypinb, HIGH);
  }
  if (content.substring(1) == "C5 94 7C 69" && but == HIGH) //change here the UID of the card/cards that you want to give access
  {
    terminal.println("Authorized access via rfid UNLOCKED");
    terminal.flush();   

    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, LOW);
    delay(200);
    digitalWrite(relaypina, HIGH); 
    digitalWrite(relaypinb, HIGH);
  }
 
}
  

    











BLYNK_WRITE(V2)
{
  int pinValuea = param.asInt(); // assigning incoming value from pin V2 to a variable
  if (pinValuea = HIGH) {
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, LOW);
    delay(200);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
    terminal.println("UNLOCKED");
    lcd.print(2, 0, "STATUS:UNLOCKED")
    terminal.flush();   
   
  } else {
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
  }
  

}
void setup()
{
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
  Terminal.println("Put your card to the reader...");
  lcd.print(4, 0, "BOOTING"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  lcd.print(4, 1, "UP")
  Delay(5000);
  lcd.clear();








  timer.setInterval(10, repeatMe);





  timer.setInterval(10, sendvalue);
  timer.setInterval(1000, wifisig);




















}




void loop()
{
  timer.run();
  Blynk.run();
}
