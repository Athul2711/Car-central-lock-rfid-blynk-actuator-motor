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
bool accc = 0, lightkey = 0;


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

#define BLYNK_FIRMWARE_VERSION        "0.1.9"

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


bool bootwithoutwifi = 0;

int whitel = 0 , redl = 0, greenl = 0 , bluel = 0 , twored = 0 , twogreen = 0 , twoblue = 0 , twowhite = 0;






#include <ESP8266WiFi.h>
#include <espnow.h>

bool r8 = 0;
const char* ssidd     = "hlo12";
const char* passs = "1231231234";


#define speaker D8


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





typedef struct struct_remote {
  int dataa;
  int datab;
  int datac;
  int datad;
} struct_remote;

struct_remote remote;








typedef struct struct_message {
  int dataa;
  int datab;
  int datac;
  unsigned long datad;
  unsigned long datae;
  int dataf;
  int datag;
  int datah;
  float x;
  float y;
  float z;
  int lightcode = 0;
} struct_message;

struct_message myData;

struct_message incomingReadings;

uint8_t broadcastAddress[] = {0x48, 0x3F, 0xDA, 0xA3, 0x77, 0xB7};

uint8_t broadcastAddress4[] = {0xCD, 0x50, 0xE3, 0x42, 0x9E, 0xF0};//changee

uint8_t broadcastAddress2[] = {0xCC, 0x50, 0xE3, 0x40, 0x9E, 0xF0};
uint8_t broadcastAddressremote[] = {0x2C, 0x3A, 0xE8, 0x20, 0x70, 0xF1};
//2c:3a:e8:20:70:f1
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
BlynkTimer timercarstart;

WidgetTerminal terminal(V9);

int xda, yda, zda;
float axx, axy, axz;
bool calibrated = false;
void gyrodatasend() {
  //  if (acc == 1) {
  mpu.update();
  //    axx = mpu.getAccX();
  //    axy = mpu.getAccY();
  //    axz = mpu.getAccZ();
  //
  //    if (axx > 0) {
  //      xda = axx * 350.0;
  //    } else {
  //      xda = axx * -350.0;
  //
  //    }
  //
  //
  //    if (axy > 0) {
  //      yda = axx * 350.0;
  //    } else {
  //      yda = axx * -350.0;
  //
  //    }
  //    if (axz > 0) {
  //      zda = axx * 350.0;
  //    } else {
  //      zda = axx * -350.0;
  //
  //    }
  //
  //    myData.x = ((xda + yda + zda));
  ////
  //yield();
  //
  //    //
  ////      myData.x = ((sqrt((axx*axx)+(axy*axy)+(axz*axz))));
  //    if (myData.x <= 0 ) {
  //      myData.x = 0;
  //        }

  myData.y =   mpu.getGyroX();
  //  myData.z = 0;

  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
  //    }

}
void gyrorun() {






  if (accvoltage > 200 && cbcbcb == 1) {

    byte status = mpu.begin();
    //
    //    Serial.print(F("MPU6050 status: "));
    //    Serial.print(status);
    //
    //    terminal.print(F("MPU6050 status: "));
    //    terminal.print(status);

    Serial.println(F("Calculating offsets, do not move MPU6050"));
    delay(100);
    mpu.calcOffsets(); // gyro and accelero
    Serial.println("Done!\n");
    if (WiFi.status() == WL_CONNECTED) {

      terminal.println("offsets");
      terminal.println(mpu.getAccXoffset());
      terminal.println(mpu.getAccYoffset());
      terminal.println(mpu.getAccZoffset());
      terminal.println(mpu.getGyroXoffset());
      terminal.println(mpu.getGyroYoffset());
      terminal.println(mpu.getGyroZoffset());


    }
    cbcbcb = 0;
    digitalWrite(D0, HIGH);

  }


  if (accvoltage < 100 && cbcbcb == 0) {
    accc = 0;
    cbcbcb = 1;

    digitalWrite(D5, HIGH);


  }



  //Serial.println(acc);

  if (acc == 1 && carmoving == 0) {
    mpu.update();


    //
    //
    //    if (WiFi.status() == WL_CONNECTED) {
    //
    //      terminal.println(mpu.getGyroX());
    //      terminal.print("    ");
    //
    //      terminal.print(mpu.getGyroY());
    //      terminal.print("    ");
    //
    //      terminal.print(mpu.getGyroZ());
    //      terminal.flush();
    //    }

    if (mpu.getGyroX() > maxval ||  mpu.getGyroY() > maxval || mpu.getGyroZ() > maxval) {





      carmoving = 1;
      //
      //
      //Serial.println(acc);
      //Serial.println(carmoving);


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

void abcde() {




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

//
//  if (carmoving == 1 && digitalRead(D6) == 0) {
//
//  }
//
//
//
//  if (carmoving == 1 && digitalRead(D7) == 0) {
//    //    digitalWrite(D0, LOW);
//
//    //    digitalWrite(D0, HIGH);
//
//  }
//








}



void switchrun() {
  int keyvalue = analogRead(A0);
  if (lightkey == 1) {

    ledonn = 1;

    lightkey = 0;

    digitalWrite(D0, LOW);
    timeram.setTimeout(25000, lightsoffrun);

  }
  if (keyvalue < 50) {


    int  atk = 1;


    if (lockposition == 1 && atk == 1) {

      unlockcode++;
      atk = 0;




myData.datab=7;
  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));


      tone(speaker, 1047);
      delay(200);
      tone(speaker, 698);
      delay(200);
      tone(speaker, 1397);
      delay(200);
      noTone(speaker);
        esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

    }


    if (lockposition == 0 && atk == 1) {
      atk = 0;
      lockcode++;
      
myData.datab=6;
  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

             tone(speaker, 1397);       delay(200);       tone(speaker, 698);       delay(200);       tone(speaker, 1047);       delay(200);       noTone(speaker);
  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

    }



  }


  if (keyvalue > 275 && keyvalue < 325) {
    int attt = 1;
    if (accc == 1 && attt == 1) {
      accc = 0;


myData.datab=6;
  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
      
             tone(speaker, 1397);       delay(200);       tone(speaker, 698);       delay(200);       tone(speaker, 1047);       delay(200);       noTone(speaker);
             tone(speaker, 1397);       delay(200);       tone(speaker, 698);       delay(200);       tone(speaker, 1047);       delay(200);       noTone(speaker);
      Blynk.virtualWrite(V11, 0);

      attt = 0;
  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

    }

    if (accc == 0 && attt == 1) {
      accc = 1;
      Blynk.virtualWrite(V11, 1);

myData.datab=7;
  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
             tone(speaker, 1047);       delay(200);       tone(speaker, 698);       delay(200);       tone(speaker, 1397);       delay(200);       noTone(speaker);
             tone(speaker, 1047);       delay(200);       tone(speaker, 698);       delay(200);       tone(speaker, 1397);       delay(200);       noTone(speaker);
             tone(speaker, 1047);       delay(200);       tone(speaker, 698);       delay(200);       tone(speaker, 1397);       delay(200);       noTone(speaker);
  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

      attt = 0;
    }



  }



  if (keyvalue > 475 && keyvalue < 525) {

myData.datab=8;
  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));




  }












}

void acofrunn() {

  digitalWrite(D5, HIGH);
}



void acrunn() {
  Serial.print("run");
  if (accc == 1 && acc == 1) {


    digitalWrite(D5, LOW);
    timeram.setTimeout((actime * 1000), acofrunn);
















  }








}









void timelock() {
  digitalWrite(D0, HIGH);
  ledonn = 0;

  if (bootwithoutwifi == 0) {

    if (hour() == 23 && minute() == 01) {
      lockcode++;
    }


    if (hour() == 21 && minute() == 01) {
      lockcode++;
    }

  }
}

void writeRegisterBit(uint8_t pos, bool state)
{
  uint8_t value;
  value = mpu.readData(0x6b);

  if (state)
  {
    value |= (1 << pos);
  } 
 else
  {
    value &= ~(1 << pos);
  }
mpu.writeData(0x6b, value);
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





if(analogRead(A0) < 900){





delay(1000);
  writeRegisterBit(6, 1);
    ESP.deepSleep(0); 
}




  //
  //  EEPROM.begin(512);
  //
  //  acofftime = EEPROM.read(310);
  //  actime = EEPROM.read(300);
  //



  WiFi.begin(ssidd, passs);
  for (int wik = 0; wik <= 20; wik++) {
    delay(500);
    yield();
    bootwithoutwifi = 1;

    if (WiFi.status() == WL_CONNECTED) {
      bootwithoutwifi = 0;
      yield();
      break;
      break;

    }
    yield();








  }
  if (bootwithoutwifi == 0) {
    Serial.println("wifion");
    BlynkEdgent.begin();
  } else {
    Serial.println("wifion");
  }
  timeraa.setInterval(1000, gyrorun);

  //  timeraa.setInterval(200, secretrun);

  timeraa.setInterval(766, switchrun);




  //    timeraa.setInterval(810, interiorrun);

  timercarstart.setInterval(167, gyrodatasend);




  //  timeraa.setInterval(3550, warningrun);

  timeraa.setInterval(20000, wifireconnect);

  timeraa.setInterval(723, datasendpulse);


  timeraa.setInterval(4053, bulbdatasend);


  timerId = timeraa.setInterval((acofftime * 1000), acrunn);


  timerab.setInterval(3080, blynksyca);



  timeraa.setInterval(40000, timelock);



  int na = 0;

  if (bootwithoutwifi == 0) {
    while (na != 3000) {
      na++;
      delayMicroseconds(1);

      yield();
      BlynkEdgent.run();

    }
  }


  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);
  esp_now_register_send_cb(OnDataSent);



  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_COMBO, 1, NULL, 0);

  esp_now_add_peer(broadcastAddress2, ESP_NOW_ROLE_COMBO, 1, NULL, 0);
  esp_now_add_peer(broadcastAddress4, ESP_NOW_ROLE_COMBO, 1, NULL, 0);




  esp_now_register_recv_cb(OnDataRecv);


  setSyncInterval(10 * 60); // Sync interval in seconds (10 minutes)

  //  WiFi.softAP(ap_ssid, ap_password);




  wifi_promiscuous_enable(1);
  wifi_set_channel(1);
  wifi_promiscuous_enable(0);




}
void bulbdatasend() {



  if (dooropen == 1 && digitalRead(D6) == 1) {
    dooropen = 0;
    ledonn = 1;

  }


  if (dooropen == 0 && digitalRead(D6) == 0 && ledonn == 0) {
    dooropen = 1;


  }


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

  if (bootwithoutwifi == 0) {
    esp_now_send(broadcastAddress2, (uint8_t *) &bulbdat, sizeof(bulbdat));
  }
}
void datasendpulse() {


  myData.dataa = carmoving;
  myData.datab = false;
  myData.datac = digitalRead(D6);
  myData.datad = lockcode;
  myData.datae = unlockcode;

  myData.dataf = hour();
  myData.datag = minute();
  myData.datah = second();


  if (bootwithoutwifi == 1) {

    myData.dataf = 18;
    myData.datag = 18;
    myData.datah = 18;


  }

  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));


}


void loop() {
  timeraa.run();

  timeram.run();



  if (WiFi.status() == WL_CONNECTED) {


    timerab.run();

    BlynkEdgent.run();

  }



  if (acc == 1) {
    timercarstart.run();


  }

}







void wifireconnect() {
  ledonn = 0;

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

  if (incomingReadings.datae != 99) {
    lockposition = incomingReadings.dataa;   // mpu6050

    acc = incomingReadings.datab;   //secret

    accvoltage = incomingReadings.datac;   //door


  } else {
    Serial.print(lightkey);
    Serial.print(ledonn);
    if (ledonn == 0) {
      lightkey = 1;




      remote.dataa = digitalRead(D6);
      remote.datab = lockposition;
      remote.datac = 0;
      remote.datad = 0;

      esp_now_send(broadcastAddressremote, (uint8_t *) &remote, sizeof(remote));





    }


  }

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



BLYNK_WRITE(V14)
{
  myData.lightcode = param.asInt(); // assigning incoming value from pin V1 to a variable

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
             tone(speaker, 1047);       delay(200);       tone(speaker, 698);       delay(200);       tone(speaker, 1397);       delay(200);       noTone(speaker);

    }


    if (lockposition == 0 && atk == 1) {
      atk = 0;
      lockcode++;
             tone(speaker, 1047);       delay(200);       tone(speaker, 698);       delay(200);       tone(speaker, 1397);       delay(200);       noTone(speaker);;

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

  timerId = timeraa.setInterval((acofftime * 1000), acrunn);


}








BLYNK_WRITE(V11)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == HIGH) {

    accc = 1;

           tone(speaker, 1047);       delay(200);       tone(speaker, 698);       delay(200);       tone(speaker, 1397);       delay(200);       noTone(speaker);

  }
  else {



    accc = 0;

    digitalWrite(D5, HIGH);
           tone(speaker, 1047);       delay(200);       tone(speaker, 698);       delay(200);       tone(speaker, 1397);       delay(200);       noTone(speaker);;
  }

}




BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == HIGH) {
    lockcode++;

           tone(speaker, 1047);       delay(200);       tone(speaker, 698);       delay(200);       tone(speaker, 1397);       delay(200);       noTone(speaker);;
  }

}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue == HIGH) {
    unlockcode++;

           tone(speaker, 1047);       delay(200);       tone(speaker, 698);       delay(200);       tone(speaker, 1397);       delay(200);       noTone(speaker);
  }

}
