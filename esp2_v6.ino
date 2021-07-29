bool iee = 0;
bool r18 = 0;
bool serp = 1;
bool cbcbcb = 0;
#define minval -15
#define maxval 10
float cartemp = 0;
bool ledonn = 0;
#include "Wire.h"
#include <MPU6050_light.h>
MPU6050 mpu(Wire);

#include <OneWire.h>
#include <DallasTemperature.h>
bool accc = 0;



int lockpositionpp = 0;
int carmovingpp = 0;
int accpp = 0;




int actime = 15;
int acofftime = 45;





const int oneWireBus = D4;
OneWire oneWire(oneWireBus);

DallasTemperature sensors(&oneWire);

#define BLYNK_TEMPLATE_ID "TMPLESEHgkrh"
#define BLYNK_DEVICE_NAME "CAR"

#define BLYNK_FIRMWARE_VERSION        "0.1.7"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG
bool seecr = 0;
bool lockposition = 0;
bool acc = 0;
int accvoltage = 0;
bool carmoving = 0;
unsigned long lockcode = 0;
unsigned long unlockcode = 0;
bool dooropen = 0;


int timerId;

bool carmovingp = 0;
bool dooropenp = 0;
unsigned long lockcodep = 0;
unsigned long  unlockcodep = 0;




int whitel = 0 , redl = 0, greenl = 0 , bluel = 0 , twored = 0 ,twogreen = 0 , twoblue = 0 , twowhite = 0;






#include <ESP8266WiFi.h>
#include <espnow.h>

bool r8 = 0;
const char* ssidd     = "hlo12";
const char* passs = "1231231234";


#define Speaker D8

#include <ESP8266_Tones.h>
ESP8266_Tones Mytone(Speaker);


typedef struct struct_messagea {
  int dataa;
  int datab;
  int datac;
  int datad;
  int datae;
  int dataf;
  int datag;
  int datah;
  int datai;
  int dataj;
  int datak;
} struct_messagea;


struct_messagea bulbdat;
















typedef struct struct_message {
  bool dataa;
  int datab;
  int datac;
  unsigned long datad;
  unsigned long datae;
} struct_message;

struct_message myData;

struct_message incomingReadings;

uint8_t broadcastAddress[] = {0x48, 0x3F, 0xDA, 0xA3, 0x77, 0xB7};


uint8_t broadcastAddress2[] = {0x48, 0x3F, 0xDA, 0xA3, 0x77, 0xa3};

//#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD


#include "BlynkEdgent.h"

#include <WidgetRTC.h>
WidgetRTC rtc;

BlynkTimer timeraa;
BlynkTimer timerab;
BlynkTimer timeram;

WidgetTerminal terminal(V9);

void gyrorun() {






  if (acc == 1 && cbcbcb == 1) {

    byte status = mpu.begin();

    Serial.print(F("MPU6050 status: "));
    Serial.print(status);

    terminal.print(F("MPU6050 status: "));
    terminal.print(status);

    Serial.println(F("Calculating offsets, do not move MPU6050"));
    delay(100);
    mpu.calcOffsets(); // gyro and accelero
    Serial.println("Done!\n");




    cbcbcb = 0;
    digitalWrite(D0, HIGH);

  }


  if (acc == 0 && cbcbcb == 0) {
    accc = 0;
    cbcbcb = 1;

    digitalWrite(D5, HIGH);

    
  }





  if (acc == 1 && carmoving == 0) {
    mpu.update();




    if (WiFi.status() == WL_CONNECTED) {

      terminal.println(mpu.getGyroX());
      terminal.print("    ");

      terminal.print(mpu.getGyroY());
      terminal.print("    ");

      terminal.print(mpu.getGyroZ());
      terminal.flush();
    }

    if (mpu.getGyroX() > maxval ||  mpu.getGyroY() > maxval || mpu.getGyroZ() > maxval) {





      carmoving = 1;




    }

    if (mpu.getGyroX() < minval ||  mpu.getGyroY() < minval || mpu.getGyroZ() < minval) {





      carmoving = 1;




    }
  }

  if (acc == 0 && carmoving == 1) {
    carmoving = 0;

    accc = 0;
    iee = 1;
    timeram.setTimeout(2000, abcde);



    digitalWrite(D5, HIGH);


  }



}

void abcde(){




  iee = 0;
}

void blynksyca() {

  Blynk.virtualWrite(V2, lockposition);
  sensors.requestTemperatures();
  cartemp = sensors.getTempCByIndex(0);
  Blynk.virtualWrite(V3, cartemp);
  Blynk.virtualWrite(V4, WiFi.RSSI());
  Blynk.virtualWrite(V5, accvoltage * 0.021012006861);
  Blynk.virtualWrite(V6, carmoving);
  Blynk.virtualWrite(V8, analogRead(A0));
}

void warningrun() {

  if (dooropen == 1 && digitalRead(D6) == 1) {
    dooropen = 0;
    ledonn = 1;
//
//    if (hour() > 17) {
//      digitalWrite(D0, LOW);
//      timeram.setTimeout(2000, lightsoffrun);



//    }

  }


  if (dooropen == 0 && digitalRead(D6) == 0 && ledonn == 0) {
    dooropen = 1;


  }

  if (carmoving == 1 && digitalRead(D6) == 0) {

    Mytone.Bleep(Speaker);
    Mytone.Bleep(Speaker);
    Mytone.Bleep(Speaker);
  }



  if (carmoving == 1 && digitalRead(D7) == 0) {
    digitalWrite(D0, LOW);

    Mytone.Bleep(Speaker);
    Mytone.Bleep(Speaker);
    digitalWrite(D0, HIGH);

  }









}



void switchrun() {


  if (analogRead(A0) < 50) {


    int  atk = 1;


    if (lockposition == 1 && atk == 1) {

      unlockcode++;
      atk = 0;
      Mytone.Tone_Up(Speaker);

    }


    if (lockposition == 0 && atk == 1) {
      atk = 0;
      lockcode++;
      Mytone.Tone_Down(Speaker);

    }



  }


  if (analogRead(A0) > 275 && analogRead(A0) < 325) {
int attt = 1;
if(accc == 1 && attt == 1){
  accc = 0;
      Mytone.Tone_Up(Speaker);
      Mytone.Tone_Up(Speaker);
  Blynk.virtualWrite(V11, 0);

    attt = 0;

}

if(accc == 0 && attt == 1){
  accc = 1;
    Blynk.virtualWrite(V11, 1);

      Mytone.Tone_Up(Speaker);
      Mytone.Tone_Up(Speaker);
      Mytone.Tone_Up(Speaker);

  attt = 0;
}



  }



  if (analogRead(A0) > 475 && analogRead(A0) < 525) {





  }












}

void acofrunn() {

  digitalWrite(D5, HIGH);
}



void acrunn() {
   Serial.print("run");
  if (accc == 1 && acc == 1) {


    digitalWrite(D5, LOW);
    timeram.setTimeout((actime*1000), acofrunn);
















  }








}









void timelock() {
  if (hour() == 23 && minute() == 01 && second() == 01) {
    lockcode++;
  }


  if (hour() == 21 && minute() == 01 && second() == 01) {
    lockcode++;
  }
}


void setup()
{


  const char *ap_ssid = "hlo123";
  const char *ap_password = "1231231234";





  pinMode(D6, INPUT_PULLUP);
  pinMode(D7, INPUT_PULLUP);
  //  pinMode(D6, INPUT_PULLUP);
  pinMode(D0, OUTPUT);
  pinMode(D5, OUTPUT);
  digitalWrite(D0, HIGH);
  digitalWrite(D5, HIGH);

  WiFi.mode(WIFI_AP_STA);

  Serial.print("Configuring access point...");

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);


  Serial.begin(115200);
  delay(100);

  sensors.begin();



  Wire.begin();

//
//  EEPROM.begin(512);
//
//  acofftime = EEPROM.read(310);
//  actime = EEPROM.read(300);
//





  BlynkEdgent.begin();

  timeraa.setInterval(1000, gyrorun);

  //  timeraa.setInterval(200, secretrun);

  timeraa.setInterval(766, switchrun);




  timeraa.setInterval(810, interiorrun);





  timeraa.setInterval(3550, warningrun);

  timeraa.setInterval(20000, wifireconnect);
  timeraa.setInterval(723, datasendpulse);


  timeraa.setInterval(4053, bulbdatasend);


  timerId = timeraa.setInterval((acofftime*1000), acrunn);


  timerab.setInterval(3080, blynksyca);



  timeraa.setInterval(980, timelock);



  int na = 0;
  while (na != 3000) {
    na++;
    delayMicroseconds(1);

    yield();
    BlynkEdgent.run();

  }



  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);
  esp_now_register_send_cb(OnDataSent);


  
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_COMBO, 1, NULL, 0);

  esp_now_add_peer(broadcastAddress2, ESP_NOW_ROLE_COMBO, 1, NULL, 0);



  
  esp_now_register_recv_cb(OnDataRecv);


  setSyncInterval(10 * 60); // Sync interval in seconds (10 minutes)
  Mytone.Imperial_March(Speaker);

//  WiFi.softAP(ap_ssid, ap_password);




  wifi_promiscuous_enable(1);
  wifi_set_channel(1);
  wifi_promiscuous_enable(0);




}
void bulbdatasend(){




  
  bulbdat.dataa = hour();
  bulbdat.datab = minute();
  bulbdat.datac = second();
  bulbdat.datad = whitel;
  bulbdat.datae = redl;
  bulbdat.dataf = greenl;
  bulbdat.datag = bluel;
  bulbdat.datah = twowhite;

  bulbdat.datai = twored;
  bulbdat.dataj = twogreen;
  bulbdat.datak = twoblue;

//
//
//
  esp_now_send(broadcastAddress2, (uint8_t *) &bulbdat, sizeof(bulbdat));

}
void datasendpulse() {


  myData.dataa = carmoving;
  myData.datab = false;
  myData.datac = dooropen;
  myData.datad = lockcode;
  myData.datae = unlockcode;




  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));


}


void loop() {
  timeraa.run();

  timeram.run();



  if (WiFi.status() == WL_CONNECTED) {


    timerab.run();

    BlynkEdgent.run();

  }

}







void wifireconnect() {

  if (carmoving == 1 && digitalRead(D6) == 0) {

    carmoving = 0;
  }



  if (carmoving == 1 && digitalRead(D7) == 0) {

    carmoving = 0;
  }




  serp = 0;
  r8 = 0;

  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssidd, passs);
  }
}



void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&incomingReadings, incomingData, sizeof(incomingReadings));
  //  Serial.print("Bytes received: ");
  //  Serial.println(len);


  lockposition = incomingReadings.dataa;   // mpu6050

  acc = incomingReadings.datab;   //secret

  accvoltage = incomingReadings.datac;   //door




}



void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  //  Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0) {
    //    Serial.println("Delivery success");
  }
  else {
    //    Serial.println("Delivery fail");
  }
}



BLYNK_CONNECTED() {
  // Synchronize time on connection
  rtc.begin();

}


void lightsoffrun() {
  digitalWrite(D0, HIGH);
  ledonn = 0;

}

void interiorrun() {

  if (lockposition == 1 && r18 == 0 && acc == 0 && iee == 0) {

    ledonn = 1;

//    if (hour() > 17) {
      digitalWrite(D0, LOW);
      timeram.setTimeout(6000, lightsoffrun);
//    }
    r18 = 1;


  }



  if (lockposition == 0 && r18 == 1 && acc == 0 && iee == 0) {
    ledonn = 1;

//    if (hour() > 17) {
      digitalWrite(D0, LOW);

      timeram.setTimeout(6000, lightsoffrun);
//    }
    r18 = 0;


  }




}




BLYNK_WRITE(V7)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == HIGH && r8 == 0) {


    r8 = 1;
    ledonn = 1;

    if (hour() > 17) {
      digitalWrite(D0, LOW);
      timeram.setTimeout(3000, lightsoffrun);
    }

  }

}









BLYNK_WRITE(V9)
{

  terminal.println("lockposition");

  terminal.println(lockposition);
  terminal.println("acc");

  terminal.println(acc);
  terminal.println("accvoltage");

  terminal.println(accvoltage);
  terminal.println("carmoving");

  terminal.println(carmoving);
  terminal.println("lockcode");

  terminal.println(lockcode);
  terminal.println("unlockcode");

  terminal.println(unlockcode);

  terminal.println("dooropen");

  terminal.println(dooropen);

  terminal.println("hour");
  terminal.println(hour());

  terminal.flush();



}













BLYNK_WRITE(V10)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == HIGH) {

    int  atk = 1;


    if (lockposition == 1 && atk == 1) {

      unlockcode++;
      atk = 0;
      Mytone.Tone_Up(Speaker);

    }


    if (lockposition == 0 && atk == 1) {
      atk = 0;
      lockcode++;
      Mytone.Tone_Down(Speaker);

    }



  }

}



BLYNK_WRITE(V12)
{
  actime = param.asInt(); // assigning incoming value from pin V1 to a variable


  EEPROM.write(300, actime);


  
}




BLYNK_WRITE(V13)
{
  acofftime = param.asInt(); // assigning incoming value from pin V1 to a variable

  EEPROM.write(310, acofftime);

  timeraa.deleteTimer(timerId);

  timerId = timeraa.setInterval((acofftime*1000), acrunn);

  
}








BLYNK_WRITE(V11)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == HIGH) {

    accc = 1;

    Mytone.Tone_Up(Speaker);

  }
  else {



    accc = 0;

    digitalWrite(D5, HIGH);
    Mytone.Tone_Down(Speaker);
  }

}




BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == HIGH) {
    lockcode++;

    Mytone.Tone_Down(Speaker);
  }

}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == HIGH) {
    unlockcode++;

    Mytone.Tone_Up(Speaker);
  }

}
