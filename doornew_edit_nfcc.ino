#include <Blynk.h>


#define BLYNK_PRINT Serial

#include <SPI.h>
#include <MFRC522.h>
#include <SimpleTimer.h> 

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define SS_PIN D4
#define RST_PIN D3
SimpleTimer timer;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "-hPnVq5cjXpbpbLvKB_QKAA8LPv0y0jS";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "hlo1";
char pass[] = "1231231234";
#define ACCESS_DELAY 2000
#define DENIED_DELAY 1000
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.


WidgetTerminal terminal(V40);



void Open()
{
  // Invert state, since button is "Active LOW"
  int isButtonPressed = !digitalRead(1);
  int butt = digitalRead(1);
  if (isButtonPressed && butt == HIGH) {
    
    digitalWrite(D6, HIGH);
    digitalWrite(D7, LOW);
    delay(200);
    digitalWrite(D6, HIGH); 
    digitalWrite(D7, HIGH); 
    terminal.println("AUTO UNLOCK");

    // Note:
    //   We allow 1 notification per 5 seconds for now.
  }

   else {
    digitalWrite(D6, LOW);
    digitalWrite(D7, HIGH);
    delay(200);
    digitalWrite(D6, HIGH); 
    digitalWrite(D7, HIGH); 
    terminal.println("AUTO LOCK");
   }
}






















BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue = HIGH) {
    digitalWrite(D6, LOW);
    digitalWrite(D7, HIGH);
    delay(200);
    digitalWrite(D6, HIGH); 
    digitalWrite(D7, HIGH);
    terminal.println("LOCKED");   
  } else {
    digitalWrite(D6, HIGH);
    digitalWrite(D7, HIGH);
  }
  
  // process received value
}






void repeatMe() {
  int but = digitalRead(1);
  
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
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "C5 94 7C 69" && but == LOW) //change here the UID of the card/cards that you want to give access
  {
    terminal.println("Authorized access via rfid LOCKED");
    digitalWrite(D6, LOW);
    digitalWrite(D7, HIGH);
    delay(200);
    digitalWrite(D6, HIGH); 
    digitalWrite(D7, HIGH);
  }
  if (content.substring(1) == "C5 94 7C 69" && but == HIGH) //change here the UID of the card/cards that you want to give access
  {
    terminal.println("Authorized access via rfid UNLOCKED");
    digitalWrite(D6, HIGH);
    digitalWrite(D7, LOW);
    delay(200);
    digitalWrite(D6, HIGH); 
    digitalWrite(D7, HIGH);
  }
 
}
  

    











BLYNK_WRITE(V2)
{
  int pinValuea = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValuea = HIGH) {
    digitalWrite(D6, HIGH);
    digitalWrite(D7, LOW);
    delay(200);
    digitalWrite(D6, HIGH);
    digitalWrite(D7, HIGH);
    terminal.println("UNLOCKED");    
  } else {
    digitalWrite(D6, HIGH);
    digitalWrite(D7, HIGH);
  }
  
  // process received value
}
void setup()
{
  pinMode(D7, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D1, INPUT);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
 
  Serial.println("Put your card to the reader...");









  attachInterrupt(digitalPinToInterrupt(1), Open, CHANGE);
  timer.setInterval(10, repeatMe);



















}




void loop()
{
  timer.run();
  Blynk.run();
}
