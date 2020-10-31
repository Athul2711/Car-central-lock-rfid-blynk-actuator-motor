//code by athulkrshna.s
//last updated on 31 october 2020


int c5 = true;


int c4 = false;

//CODE BY ATHULKRISHNA>S
//
int atk1 = false;
int atk2 = false;
int atk3 = false;
int atk4 = false;
#include <Blynk.h>
int la = 0;
#include <WiFiUdp.h>  // For OTA
#include <ArduinoOTA.h>  // For OTA
//#define BLYNK_PRINT Serial
#include <TimeLib.h>
#include <SPI.h>
#include <MFRC522.h>
#include <SimpleTimer.h>

//#include <WidgetRTC.h>
int fifty = 0;

#include <Arduino.h>
//#include <IRrecv.h>
//#include <IRremoteESP8266.h>
//#include <IRac.h>
//#include <IRtext.h>

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int milan = 1;
#define SS_PIN D4
#define RST_PIN D3
#define relaypina D2
#define relaypinb D0
String lockdata = String();
#define sensorpin D1


#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>  // For OTA w/ ESP8266

unsigned long oped = 0;
//Pins



ESP8266WebServer server(80);






int programSwitch = 2;       // If this is high we program a new code.
// Status LED

int threshold = 604;           // Minimum signal from the piezo to register as a knock
const int rejectValue = 100;        // If an individual knock is off by this percentage of a knock we don't unlock..
const int averageRejectValue = 96; // If the average timing of the knocks is off by this percent we don't unlock.
const int knockFadeTime = 150;     // milliseconds we allow a knock to fade before we listen for another one. (Debounce timer.)
const int lockTurnTime = 650;      // milliseconds that we run the motor to get it to go a half turn.

const int maximumKnocks = 5;       // Maximum number of knocks to listen for.
const int knockComplete = 500;     // Longest time to wait for a knock before we assume that it's finished.


// Variables.
int secretCode[maximumKnocks] = {1, 1, 1, 0, 0};  // Initial setup: "Shave and a Hair Cut, two bits."
int knockReadings[maximumKnocks];   // When someone knocks this array fills with delays between knocks.
int knockSensorValue = 0;           // Last reading of the knock sensor.
int programButtonPressed = false;   // Flag so we remember the programming button setting at the end of the cycle.

int thresh = false;



















int athul = 1;

int autolock = 1;

int opener = 1;
int closer = 1;



#include <WidgetRTC.h>





const long interval = 1000;


unsigned long previousMillis = 0;
int atk = LOW;
int valuaa = HIGH;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "qbZbJK2pM9-35lAhV2RixqkH0AGZCLHM";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "hlo12";
char ssidd[] = "car";

char passs[] = "1231231234";
char ACCESS_KEY[] = "09 97 3D 59";
char ACCESS_CARD[] = "C7 46 62 40";



BlynkTimer timer;
BlynkTimer timera;
BlynkTimer timerb;


MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
WidgetRTC rtc;


WidgetTerminal terminal(V40);


WidgetLED led(V10);

WidgetLCD lcd(V100);


void autounlock() {
  valuaa = digitalRead(sensorpin);












}


void handleRoot() {
  char temp[400];
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;

  snprintf(temp, 400,

           "<html>\
  <head>\
    <meta http-equiv='refresh' content='5'/>\
    <title>KL-17-G-9411 Admin Page</title>\
    <style>\
      body { background-color: #96c7f2; font-family: Arial, Helvetica, Sans-Serif; Color: #634400; }\
    </style>\
  </head>\
  <body>\
    <h1>##-##-#-#### Admin Page</h1><br>\n\n\
     <h1>AUTHRISED ACESS ONLY!</h1><br>\n\n\
    <p>Uptime: %02d:%02d:%02d</p>\
    <p>owner name</p>\
    Athulkrishna S\
    sub owner name\
    phone nunmer</p>\
  </body>\
</html>",

           hr, min % 60, sec % 60
          );
  server.send(200, "text/html", temp);
}


void knooo() { // lock
  server.send(200, "text/html", "ccc");
}
void handleRootvv() { // lock
  server.send(200, "text/html", lockdata);
}
void handleRoota() { // lock
  server.send(200, "text/html", "LOCKED");


  oped = oped + 1;
  athul == 0;
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




}


void handleRootb() {
  server.send(200, "text/html", "UNLOCKED");



  oped = oped + 1;
  athul == 0;
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






}

BLYNK_CONNECTED() {
  // Synchronize time on connection
  rtc.begin();
}






//void ircode(){




//}













void lock() {

  int aaab = digitalRead(D1);

  if (aaab == HIGH) {


    lcd.print(1, 0, "STATUS:LOCKED..");
  } else {
    lcd.print(1, 0, "STATUS:UNLOCKED");
  }



}

void sendvalue()
{
  int aaab = digitalRead(sensorpin);
  Blynk.virtualWrite(V12, aaab);
  if (WiFi.status() == WL_CONNECTED) {
    long rssi = WiFi.RSSI();


    lcd.print(0, 1, "Signal:");
    lcd.print(7, 1, rssi);

  }






}







BLYNK_WRITE(V40)
{

  int LAAAAA = param.asInt();
  if (String("power") == param.asStr()) {
    thresh = true;
    terminal.println("power of secret lock");
    terminal.flush();
  }

  if (thresh == true) {
    LAAAAA = threshold;
    thresh = false;

  }



  if (String("sensitivity") == param.asStr()) {
    atk1 = true;
    terminal.println("sensitivity of secret lock");
    terminal.flush();
  }

  if (atk1 == true) {
    LAAAAA = averageRejectValue;
    atk1 = false;

  }


  if (String("save") == param.asStr()) {
    terminal.println("programming protocol activated");

    terminal.flush();
    programButtonPressed = true;
  }



  if (String("reset") == param.asStr()) {
    terminal.println("Data resetted");
    c4 = false;
    la = 0;
    terminal.flush();
  }


  if (String("saveoff") == param.asStr()) {
    programButtonPressed = false;
  }


  if (String("activatetimelock") == param.asStr()) {
    opener = 1;
    closer = 1;

    terminal.println("activating time lock ");
    terminal.flush();
  }




  if (String("deactivatetimelock") == param.asStr()) {
    opener = 0;
    closer = 0;

    terminal.println("deactivating time lock ");
    terminal.flush();
  }





  if (String("deactivateautolock") == param.asStr()) {
    autolock = 0;


    terminal.println("deactivating auto lock ");
    terminal.flush();
  }




  if (String("activateautolock") == param.asStr()) {
    autolock = 1;


    terminal.println("activating auto lock ");
    terminal.flush();
  }










  if (String("data") == param.asStr()) {


    terminal.println("times opened=");
    terminal.println(oped);
    terminal.println(" time started=");
    terminal.println(millis());
    terminal.println(" 50 started=");
    terminal.println(fifty);

    String currentTime = String(hour()) + ":" + minute() + ":" + second();
    //secretCode
    terminal.println(currentTime);
    terminal.println(la);
    terminal.println(WiFi.localIP());

    IPAddress myIP = WiFi.softAPIP();
    terminal.print("AP IP address: ");
    terminal.println(myIP);
    terminal.flush();
    //
    //


    //   terminal.flush();
  }



  if (String("lockdata") == param.asStr()) {
    terminal.println(lockdata);
    terminal.flush();

  }






  if (String("reboot") == param.asStr()) {

    ESP.restart();
    terminal.println("activating auto lock ");
    terminal.flush();
  }



  if (String("poweroff") == param.asStr()) {

    terminal.println("powering down");
    terminal.flush();
    digitalWrite(D3, LOW);
    ESP.deepSleep(0);

  }














}




BLYNK_WRITE(V4)
{
  int lol = param.asInt(); // assigning incoming value from pin V1 to a variable
  int sens = digitalRead(sensorpin);
  if (lol = HIGH && atk == LOW && sens == HIGH) {
    terminal.println("LOCKED via autolock");
    terminal.flush();
    athul == 0;
    Blynk.virtualWrite(V4, 0);
    oped = oped + 1;
    digitalWrite(relaypina, LOW);
    digitalWrite(relaypinb, HIGH);
    delay(200);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
  }


  if (lol = HIGH && atk == LOW && sens == LOW) {
    terminal.println("UNLOCKED via autounlock");
    terminal.flush();
    athul == 0;
    Blynk.virtualWrite(V4, 0);
    oped = oped + 1;
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, LOW);
    delay(200);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
  }


}




BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue = HIGH) {
    Blynk.virtualWrite(V74, 0);
    Blynk.virtualWrite(V1, 0);
    oped = oped + 1;
    athul == 0;
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

    String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
    lockdata = lockdata + String("LOCKED") + "," + currentTime + "\r\n";
  }


}
























void loWW() {
  digitalWrite(D8, LOW);
  c4 = false;
}


void repeatMea() {

  mfrc522.PCD_Init();   // Initiate MFRC522


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
  String content = "";
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
    athul == 0;
    oped = oped + 1;
    terminal.println("Authorized access via rfid LOCKED");
    digitalWrite(relaypina, LOW);
    digitalWrite(relaypinb, HIGH);
    atk = HIGH;
    delay(250);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
    delay(800);
    atk = LOW;

    String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
    lockdata = lockdata + String("LOCKED") + "," + currentTime + "\r\n";
  }
  if (content.substring(1) == ACCESS_KEY && but == HIGH) //change here the UID of the card/cards that you want to give access
  {
    athul == 0;
    oped = oped + 1;
    terminal.println("Authorized access via rfid UNLOCKED");
    terminal.flush();
    atk = HIGH;
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, LOW);
    delay(250);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
    delay(800);
    atk = LOW;

    String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
    lockdata = lockdata + String("UNLOCKED") + "," + currentTime + "\r\n";
  }



  if (content.substring(1) == ACCESS_CARD && but == HIGH) //change here the UID of the card/cards that you want to give access
  {
    athul == 0;
    oped = oped + 1;
    terminal.println("Authorized access via rfid UNLOCKED");
    terminal.flush();
    atk = HIGH;
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, LOW);
    delay(250);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
    delay(800);
    atk = LOW;

    String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
    lockdata = lockdata + String("UNLOCKED") + "," + currentTime + "\r\n";
  }

  if (content.substring(1) == ACCESS_CARD && but == LOW) //change here the UID of the card/cards that you want to give access
  {
    athul == 0;
    oped = oped + 1;
    terminal.println("Authorized access via rfid LOCKED");
    digitalWrite(relaypina, LOW);
    atk = HIGH;
    digitalWrite(relaypinb, HIGH);
    delay(250);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
    delay(800);
    atk = LOW;

    String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
    lockdata = lockdata + String("LOCKED") + "," + currentTime + "\r\n";
  }


}

/*


  BLYNK_WRITE(V43)
  { long rssi = WiFi.RSSI();
  int pinValuea = param.asInt(); // assigning incoming value from pin V2 to a variable

  if (pinValuea = 1 && rssi > -80) {

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

  }


  }



  BLYNK_WRITE(V44)
  { long rssi = WiFi.RSSI();
  int pinValuea = param.asInt(); // assigning incoming value from pin V2 to a variable

  if (pinValuea = 1 && rssi < -72) {

    digitalWrite(relaypina, LOW);
    digitalWrite(relaypinb, HIGH);
    atk = HIGH;

    delay(200);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
    terminal.println("LOCKED");
    lcd.clear();

    lcd.print(1, 0, "STATUS:LOCKED..");
    terminal.flush();
    delay(1800);
    atk = LOW;

  }


  }


*/



void offf()
{

  digitalWrite(relaypina, HIGH);
  digitalWrite(relaypinb, HIGH);

}



void clockDisplay()
{
  // You can call hour(), minute(), ... at any time
  // Please see Time library examples for details




  int buuut = digitalRead(sensorpin);


  if (hour() == 8 && minute() == 00 && second() == 00 && opener == 1) {
    oped = oped + 1;
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, LOW);
    atk = HIGH;
    delay(200);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
    terminal.println("UNLOCKED via time");
    lcd.clear();
    lcd.print(1, 0, "STATUS:UNLOCKED");
    terminal.flush();
    delay(1800);
    atk = LOW;
    athul = 1;

    String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
    lockdata = lockdata + String("UNLOCKED") + "," + currentTime + "\r\n";
  }


  if (hour() == 21 && minute() == 00 && second() == 00  && closer == 1) {
    oped = oped + 1;
    digitalWrite(relaypina, LOW);
    digitalWrite(relaypinb, HIGH);
    atk = HIGH;
    delay(200);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
    terminal.println("LOCKED LOCKED via time");
    lcd.clear();
    lcd.print(1, 0, "STATUS:LOCKED via time");
    terminal.flush();
    delay(1800);
    atk = LOW;

    String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
    lockdata = lockdata + String("LOCKED") + "," + currentTime + "\r\n";
  }


  if (hour() == 23 && minute() == 00 && second() == 00  && closer == 1) {
    oped = oped + 1;
    digitalWrite(relaypina, LOW);
    digitalWrite(relaypinb, HIGH);
    atk = HIGH;
    delay(200);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
    terminal.println("LOCKED LOCKED via time");
    lcd.clear();
    lcd.print(1, 0, "STATUS:LOCKED via time");
    terminal.flush();
    delay(1800);
    atk = LOW;

    String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
    lockdata = lockdata + String("LOCKED") + "," + currentTime + "\r\n";
  }




  if (hour() == 10 && minute() == 00 && second() == 00) {
    if (day() == 4 || day() == 11 || day() == 18 || day() == 25) {
      lockdata = String("");

    }

  }

  if (hour() == 10 && minute() == 00 && second() == 00 && closer == 1 && athul == 1) {
    oped = oped + 1;
    digitalWrite(relaypina, LOW);
    digitalWrite(relaypinb, HIGH);
    atk = HIGH;
    delay(200);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
    terminal.println("LOCKED");
    lcd.clear();
    lcd.print(1, 0, "STATUS:LOCKED via time");
    terminal.flush();
    delay(1800);
    atk = LOW;

    String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
    lockdata = lockdata + String("LOCKED") + "," + currentTime + "\r\n";
  }















}

































BLYNK_WRITE(V2)
{
  int pinValuea = param.asInt(); // assigning incoming value from pin V2 to a variable
  if (pinValuea = HIGH) {
    Blynk.virtualWrite(V2, 0);
    oped = oped + 1;
    Blynk.virtualWrite(V75, 0);
    athul == 0;
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

    String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
    lockdata = lockdata + String("UNLOCKED") + "," + currentTime + "\r\n";
  }


}
void setup()
{
  pinMode(relaypina, OUTPUT);
  pinMode(relaypinb, OUTPUT);
  pinMode(D8, OUTPUT);

  pinMode(sensorpin, INPUT);
  digitalWrite(relaypina, HIGH);
  digitalWrite(relaypinb, HIGH);
  // Debug console
  WiFi.mode(WIFI_AP_STA);
  //  Serial.begin(115200);
  setSyncInterval(10 * 60); // Sync interval in seconds (10 minutes)
  WiFi.softAP(ssidd, passs);

  WiFi.begin(ssid, passs);


  Blynk.begin(auth, ssid, passs);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  lcd.clear();
  terminal.clear();
  terminal.println("device online");
  terminal.println("available commands");
  terminal.println("power__save__activatetimelock_saveoff_deactivatetimelock__activateautolock___deactivateautolock__data_poweroff__reboot");

  terminal.flush();


  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
    terminal.println("MDNS responder started");
    Serial.println("MDNS responder started");
    MDNS.addService("esp", "tcp", 8080);
  }

  ArduinoOTA.begin();  // For OTA




  timera.setInterval(1000L, clockDisplay);
  timera.setInterval(5000L, offf);
  timera.setInterval(10000, loWW);
  timera.setInterval(10, repeatMe);


  timera.setInterval(100000, laa);
  //  timera.setInterval(1, ircode);

  timera.setInterval(4000, repeatMea);

  //  timera.setInterval(1000, tim);




  timer.setInterval(1000, sendvalue);
  timer.setInterval(2000, lock);//lcd

  led.on();




  timerb.setInterval(1500, autounlock);//read value



  server.onNotFound(handleNotFound);

  server.on("/", handleRoot);

  server.on("/lock", handleRoota);
  server.on("/data", handleRootvv);
  server.on("/knock", knooo);

  server.on("/unlock", handleRootb);
  server.begin();
  Serial.println("HTTP server started");







}












void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
}






//
//
//
//
//BLYNK_WRITE(V54) {
//  switch (param.asInt())
//  {
//    case 1:
//      opener = 1;
//      terminal.println("time open activated");
//      terminal.flush();
//      closer = 1;
//      autolock = 1;
//
//      break;
//    case 2:
//      opener = 0;
//      terminal.println("time open disabled");
//      terminal.flush();
//      closer = 0;
//      autolock = 0;
//
//    case 3:
//      terminal.println("times opened=");
//      terminal.println(oped);
//      terminal.flush();
//      break;
//    case 4:
//      String currentTime = String(hour()) + ":" + minute() + ":" + second();
//
//      terminal.println(currentTime);
//      terminal.flush();
//
//
//
//      break;
//
//
//  }
//}
//
//
//
//
//















void listenToSecretKnock() {
  terminal.println("knock starting");





  terminal.flush();
  int i = 0;
  // First lets reset the listening array.
  for (i = 0; i < maximumKnocks; i++) {
    knockReadings[i] = 0;
    delay(1);
  }

  int currentKnockNumber = 0;             // Incrementer for the array.
  int startTime = millis();               // Reference for when this knock started.
  int now = millis();

  if (programButtonPressed == true) {
  }
  delay(knockFadeTime);                                 // wait for this peak to fade before we listen to the next one.
  if (programButtonPressed == true) {
  }
  do {
    //listen for the next knock or wait for it to timeout.
    knockSensorValue = analogRead(A0);
    if (knockSensorValue >= threshold) {                 //got another knock...
      //record the delay time.













      now = millis();
      knockReadings[currentKnockNumber] = now - startTime;
      currentKnockNumber ++;                             //increment the counter
      startTime = now;
      // and reset our timer for the next knock
      //      digitalWrite(greenLED, LOW);
      if (programButtonPressed == true) {
        //        digitalWrite(redLED, LOW);                       // and the red one too if we're programming a new knock.
      }
      delay(knockFadeTime);                              // again, a little delay to let the knock decay.
      //      digitalWrite(greenLED, HIGH);
      if (programButtonPressed == true) {
        //        digitalWrite(redLED, HIGH);
      }
    }

    now = millis();

    //did we timeout or run out of knocks?
  } while ((now - startTime < knockComplete) && (currentKnockNumber < maximumKnocks));

  //we've got our knock recorded, lets see if it's valid
  if (programButtonPressed == false) {          // only if we're not in progrmaing mode.
    if (validateKnock() == true) {
      triggerDoorUnlock();
    } else {
      la++;
      terminal.println("Secret knock failed.");
      //      digitalWrite(greenLED, LOW);      // We didn't unlock, so blink the red LED as visual feedback.

      //      digitalWrite(greenLED, HIGH);
    }
  } else { // if we're in programming mode we still validate the lock, we just don't do anything with the lock
    validateKnock();
    // and we blink the green and red alternately to show that program is complete.
    terminal.println("New lock stored.");
    programButtonPressed = false;

    terminal.flush();
    //    digitalWrite(redLED, LOW);
    //    digitalWrite(greenLED, HIGH);

  }
}


// Runs the motor (or whatever) to unlock the door.
void triggerDoorUnlock() {





  if (c4 == true) {
    Serial.println("Door unlocked!");
    int i = 0;

    // turn the motor on for a bit.

    c4 = false;


    c5 = false;





    int tiii = hour();
    int sens = digitalRead(sensorpin);
    if (sens == LOW && tiii >= 7 && tiii < 23) {
      terminal.println("LOCKED via autolock");
      terminal.flush();
      athul == 0;
      Blynk.virtualWrite(V4, 0);
      oped = oped + 1;
      digitalWrite(relaypina, LOW);
      digitalWrite(relaypinb, HIGH);
      delay(200);
      digitalWrite(relaypina, HIGH);
      digitalWrite(relaypinb, HIGH);

      String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
      lockdata = lockdata + String("ATKLOCKED") + "," + currentTime + "\r\n";
    }


    if (sens == HIGH && tiii >= 7 && tiii < 23) {
      terminal.println("UNLOCKED via autounlock");
      terminal.flush();
      athul == 0;
      Blynk.virtualWrite(V4, 0);
      oped = oped + 1;
      digitalWrite(relaypina, HIGH);
      digitalWrite(relaypinb, LOW);
      delay(200);
      digitalWrite(relaypina, HIGH);
      digitalWrite(relaypinb, HIGH);
      delay(2000);

      String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
      lockdata = lockdata + String("ATKUNLOCKED") + "," + currentTime + "\r\n";
    }




  }







  if (c4 == false && c5 == true) {
    c4 = true;
    c5 = false;
    digitalWrite(D8, HIGH );

  }



  c5 = true;









  // Blink the green LED a few times for more visual feedback.




}

// Sees if our knock matches the secret.
// returns true if it's a good knock, false if it's not.
// todo: break it into smaller functions for readability.
boolean validateKnock() {
  int i = 0;

  // simplest check first: Did we get the right number of knocks?
  int currentKnockCount = 0;
  int secretKnockCount = 0;
  int maxKnockInterval = 0;               // We use this later to normalize the times.

  for (i = 0; i < maximumKnocks; i++) {
    if (knockReadings[i] > 0) {
      currentKnockCount++;
    }
    if (secretCode[i] > 0) {          //todo: precalculate this.
      secretKnockCount++;
    }

    if (knockReadings[i] > maxKnockInterval) {  // collect normalization data while we're looping.
      maxKnockInterval = knockReadings[i];
    }
  }

  // If we're recording a new knock, save the info and get out of here.
  if (programButtonPressed == true) {
    for (i = 0; i < maximumKnocks; i++) { // normalize the times
      secretCode[i] = map(knockReadings[i], 0, maxKnockInterval, 0, 100);
    }
    // And flash the lights in the recorded pattern to let us know it's been programmed.
    //      digitalWrite(greenLED, LOW);
    //      digitalWrite(redLED, LOW);
    //      delay(1000);
    //      digitalWrite(greenLED, HIGH);
    //      digitalWrite(redLED, HIGH);
    //      delay(50);
    for (i = 0; i < maximumKnocks ; i++) {
      //        digitalWrite(greenLED, LOW);
      //        digitalWrite(redLED, LOW);
      // only turn it on if there's a delay
      if (secretCode[i] > 0) {
        delay( map(secretCode[i], 0, 100, 0, maxKnockInterval)); // Expand the time back out to what it was.  Roughly.
        //          digitalWrite(greenLED, HIGH);
        //          digitalWrite(redLED, HIGH);
      }
      delay(50);
    }
    return false;   // We don't unlock the door when we are recording a new knock.
  }

  if (currentKnockCount != secretKnockCount) {
    return false;
  }

  /*  Now we compare the relative intervals of our knocks, not the absolute time between them.
      (ie: if you do the same pattern slow or fast it should still open the door.)
      This makes it less picky, which while making it less secure can also make it
      less of a pain to use if you're tempo is a little slow or fast.
  */
  int totaltimeDifferences = 0;
  int timeDiff = 0;
  for (i = 0; i < maximumKnocks; i++) { // Normalize the times
    knockReadings[i] = map(knockReadings[i], 0, maxKnockInterval, 0, 100);
    timeDiff = abs(knockReadings[i] - secretCode[i]);
    if (timeDiff > rejectValue) { // Individual value too far out of whack
      return false;
    }
    totaltimeDifferences += timeDiff;
  }
  // It can also fail if the whole thing is too inaccurate.
  if (totaltimeDifferences / secretKnockCount > averageRejectValue) {
    return false;
  }

  return true;

}















































void loop()
{

  server.handleClient();
  MDNS.update();

  ArduinoOTA.handle();
  if (WiFi.status() == WL_CONNECTED) {
    timer.run();
    Blynk.run();
  }
  if (autolock == 1) {
    timerb.run();

    int valuab = digitalRead(sensorpin);

    if (valuaa != valuab && valuab == HIGH && atk == LOW) {
      terminal.println("LOCKED via autounlock");
      terminal.flush();
      oped = oped + 1;
      atk = HIGH;
      digitalWrite(relaypina, LOW);
      digitalWrite(relaypinb, HIGH);
      delay(200);
      digitalWrite(relaypina, HIGH);
      digitalWrite(relaypinb, HIGH);
      delay(1500);
      atk = LOW;

      String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
      lockdata = lockdata + String("LOCKED") + "," + currentTime + "\r\n";
    }
    if (valuab != valuaa && valuab == LOW && atk == LOW) {
      terminal.println("UNLOCKED via autounlock");
      terminal.flush();
      atk = HIGH;

      oped = oped + 1;
      digitalWrite(relaypina, HIGH);
      digitalWrite(relaypinb, LOW);
      delay(200);
      digitalWrite(relaypina, HIGH);
      digitalWrite(relaypinb, HIGH);
      delay(1500);
      atk = LOW;


      String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
      lockdata = lockdata + String("UNLOCKED") + "," + currentTime + "\r\n";

    }





  }
  timera.run();


  // Listen for any knock at all.
  knockSensorValue = analogRead(A0);


  if (knockSensorValue >= threshold && la < 5) {
    listenToSecretKnock();

    String currentTime = String(hour()) + ":" + minute() + ":" + second() + "," + day() + " " + month() + " " + year();
    lockdata = lockdata + String("HANDLE TRIGGERED") + "," + currentTime + "\r\n";

  }
}

//4294867195


void laa() {
  la = 0;
  int c3 = millis();
  if (c3 > 4294867195) {
    fifty++;

  }
}
