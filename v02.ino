










//
//realy a and b door
//sens a
//


int headdallow = 0;


int acbutton = 0;
int mistbutton = 0;

int headlighton = 0;
#include <OneWire.h>
#include <DallasTemperature.h>
#define minval -12

#define maxval 12

#include "Wire.h"
#include <MPU6050_light.h>
MPU6050 mpu(Wire);



float cartemp = 0;

int atk = 1;
int atka = 1;
int actemp = 0;
int atkb = 1;
int atkbb = 1;
int acc = 0;
int carmoving = 0;
int gyy = 1;
int gyx = 1;

char ACCESS_KEY[] = "09 97 3D 59";
char ACCESS_CARD[] = "46 C6 24 52";


unsigned long oped = 0;
#define BLYNK_TEMPLATE_ID "TMPLU-f_0Vmb"
#define BLYNK_DEVICE_NAME "CAR"

#define BLYNK_FIRMWARE_VERSION        "0.1.4"

#define BLYNK_PRINT Serial
#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD

#include "BlynkEdgent.h"


#include <SPI.h>
#include <MFRC522.h>
#include <WidgetRTC.h>

const int oneWireBus = 4;
OneWire oneWire(oneWireBus);

DallasTemperature sensors(&oneWire);



const char* ssidd     = "hlo12";
const char* passs = "1231231234";









#define SS_PIN 21
#define RST_PIN 22








//mfrc 18 19 21 22 23    //18 white-red  19 grey-browngrey 21 purple-black 22 blue-blue  23 green-green    3.3 yellow-yellow  gnd orange-orange
//mpu6050 32 , 33
//temp 4   // yellow
//26  

#include <Tone32.h>

#define BUZZER_PIN 26        //purple
#define BUZZER_CHANNEL 0    


#define relaypina 25  //door     //yellow
#define relaypinb 17  // door   //yellow
#define relaypinc 13 //ac        //blue
#define relaypind 16 //headlight   //red

#define led2pin 12 //led   white status grey rfid door    

//red 5v

#define sensorpina 14 //door actuator   ...           yellow  
#define sensorpinb 27 //secret lock     ...              orange
#define sensorpinc 15//handbrake  .// pull up           blue
#define sensorpind 5//door close   .// pull up           red

#define sensorpine 34//acc power       ...//voltage divider   white




#define switchpin1 35 //switch  // pull up      //headlight      grey
#define switchpin2 36 //switch2// pull up         //acbutton    blue
#define switchpin3 39//switch 3 .    // pull up //mistbutton   purple


//32
//33

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
WidgetRTC rtc;

BlynkTimer timerac;
BlynkTimer timeraa;
BlynkTimer timerab;
WidgetTerminal terminal(V2);


int16_t ax, ay, az;
int16_t gx, gy, gz;
#define OUTPUT_READABLE_ACCELGYRO



void timelock() {
  if (hour() == 23 && minute() == 00 && second() == 00) {
    lock();
  }


  if (hour() == 21 && minute() == 00 && second() == 00) {
    lock();
  }
}


void buttonn()
{




  if (digitalRead(switchpin1) == LOW) {


    tone(BUZZER_PIN, NOTE_D4, 200, BUZZER_CHANNEL);
    tone(BUZZER_PIN, NOTE_D5, 200, BUZZER_CHANNEL);
    tone(BUZZER_PIN, NOTE_D6, 200, BUZZER_CHANNEL);
    noTone(BUZZER_PIN, BUZZER_CHANNEL);

    if (headdallow == 1) {
      hedd();

      delay(100);
    }

    delay(4000);
  }


  if (digitalRead(switchpin2) == LOW) {

    int abcde = 1;
    if (acbutton == 0) {
      abcde = 0;
      acbutton = 1;



      tone(BUZZER_PIN, NOTE_D4, 200, BUZZER_CHANNEL);
      tone(BUZZER_PIN, NOTE_D5, 200, BUZZER_CHANNEL);
      tone(BUZZER_PIN, NOTE_D6, 200, BUZZER_CHANNEL);
      noTone(BUZZER_PIN, BUZZER_CHANNEL);


    }


    if (acbutton == 1 && abcde == 1) {
      abcde = 0;
      acbutton = 0;


      tone(BUZZER_PIN, NOTE_D6, 200, BUZZER_CHANNEL);
      tone(BUZZER_PIN, NOTE_D5, 200, BUZZER_CHANNEL);
      tone(BUZZER_PIN, NOTE_D4, 200, BUZZER_CHANNEL);
      noTone(BUZZER_PIN, BUZZER_CHANNEL);
    }
    delay(4000);

  }


  if (digitalRead(switchpin3) == LOW) {



    int abcdef = 1;
    if (mistbutton == 0) {
      abcdef = 0;
      mistbutton = 1;




      tone(BUZZER_PIN, NOTE_D4, 200, BUZZER_CHANNEL);
      tone(BUZZER_PIN, NOTE_D5, 200, BUZZER_CHANNEL);
      tone(BUZZER_PIN, NOTE_D6, 200, BUZZER_CHANNEL);
      noTone(BUZZER_PIN, BUZZER_CHANNEL);




    }


    if (mistbutton == 1 && abcdef == 1) {
      abcdef = 0;
      mistbutton = 0;




      tone(BUZZER_PIN, NOTE_D6, 200, BUZZER_CHANNEL);
      tone(BUZZER_PIN, NOTE_D5, 200, BUZZER_CHANNEL);
      tone(BUZZER_PIN, NOTE_D4, 200, BUZZER_CHANNEL);
      noTone(BUZZER_PIN, BUZZER_CHANNEL);
    }
    delay(4000);



  }










}

void warningg() {

  if (carmoving == 1 && digitalRead(sensorpinc) == HIGH) {
    digitalWrite(led2pin, HIGH);

    tone(BUZZER_PIN, NOTE_C4, 500, BUZZER_CHANNEL);
    noTone(BUZZER_PIN, BUZZER_CHANNEL);

    delay(500);
    digitalWrite(led2pin, LOW);
  }


  if (carmoving == 1 && digitalRead(sensorpind) == LOW) {
    digitalWrite(led2pin, HIGH);

    tone(BUZZER_PIN, NOTE_B4, 500, BUZZER_CHANNEL);
    noTone(BUZZER_PIN, BUZZER_CHANNEL);
    delay(500);
    digitalWrite(led2pin, LOW);

  }








}

void setup()
{

  pinMode(relaypina, OUTPUT);
  pinMode(relaypinb, OUTPUT);
  pinMode(relaypinc, OUTPUT);
  pinMode(relaypind, OUTPUT);
  digitalWrite(relaypina, HIGH);
  digitalWrite(relaypinb, HIGH);
  digitalWrite(relaypinc, HIGH);
  digitalWrite(relaypind, HIGH);

  pinMode(switchpin1, INPUT);
  pinMode(switchpin2, INPUT);
  pinMode(switchpin3, INPUT);

  pinMode(sensorpina, INPUT);
  pinMode(sensorpinb, INPUT);
  pinMode(sensorpinc, INPUT);
  pinMode(sensorpind, INPUT);
  pinMode(sensorpine, INPUT);





  pinMode(led2pin, OUTPUT);
  digitalWrite(led2pin, LOW);

  ///////////////
  /////////////////////
  setCpuFrequencyMhz(160);
  Serial.begin(115200);
  delay(100);
  BlynkEdgent.begin();

  setSyncInterval(10 * 60); // Sync interval in seconds (10 minutes)
  timerac.setInterval(10, rfid);

  timeraa.setInterval(10000, wifireconnect);

  timeraa.setInterval(300, acccc); // key
  timeraa.setInterval(300, gyro); // key


  timeraa.setInterval(800, autolock);


  timeraa.setInterval(600, buttonn);

  timeraa.setInterval(2000, warningg);


  timerac.setInterval(5000, resetall);

  timeraa.setInterval(500, timelock);


  timeraa.setInterval(50, secretlock);



  timerab.setInterval(2000, datasync);


  SPI.begin();
  mfrc522.PCD_Init();
  int na = 0;
  while (na != 3000) {
    na++;
    delayMicroseconds(1);


    BlynkEdgent.run();
  }


  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin(33, 32);
  Wire.begin(33, 32);

  sensors.begin();

  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);


  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");

}
void resetall() {

  if (headdallow == 0) {
    digitalWrite(relaypind, HIGH);

  }





}


void secretlock() {
  if (digitalRead(sensorpinb) == HIGH) {
    int pulse = pulseIn(sensorpinb, HIGH, 3000000);
    terminal.println(pulse);
    terminal.flush();
    if (pulse > 900 && pulse <= 1000) {
      int but = digitalRead(sensorpina);
      int rep = 1;
      if (but == HIGH && rep == 1) {
        rep = 0;
        unlock();
      }
      if (but == LOW && rep == 1) {
        rep = 0;
        lock();
      }
    }
  }
}



void headlightofff() {
  headdallow = 0;
}



void gyro() {


  if (acc == 1 && gyx == 1) {

    mpu.update();



    if (mpu.getAngleX() > maxval || mpu.getAngleX() < minval && mpu.getAngleY() > maxval || mpu.getAngleY()  < minval && mpu.getAngleZ() > maxval || mpu.getAngleZ() < minval) {

      if (gyy == 1) {

        lock();
        gyy = 0;
        gyx = 0;
        carmoving = 1;
      }



      gyy = 1;
    }

  }






















}




void autolock() {

  //////////////

  int but = digitalRead(sensorpina);
  if (but == HIGH && atk == 1 && atka == 1) {

    lock();
    atka = 0;
    atk = 0;

  }


  if (but == LOW && atk == 1 && atka == 0) {
    atka = 1;
    atk = 0;
    unlock();

  }



  atk = 1;









}


void acccc() {

  int buu = analogRead(sensorpine);
  if (buu > 1000 && atkb == 1 && atkbb == 1) {
    acc = 1;
    atkbb = 0;
    atkb = 0;
  mpu.calcOffsets(); // gyro and accelero

  }


  if (buu == LOW && atkb == 1 && atkbb == 0) {
    atkbb = 1;
    atkb = 0;
    unlock();
    gyx = 1;
    acc = 0;
    carmoving = 0;
    headdallow = 1;

    timeraa.setTimeout(200000, headlightofff);
  }

  atkb = 1;
}
void wifireconnect() {

  digitalWrite(relaypina, HIGH);
  digitalWrite(relaypinb, HIGH);

  mfrc522.PCD_Init();
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssidd, passs);
  }
}
void loop() {

  timerac.run();
  timeraa.run();

  //
  if (WiFi.status() == WL_CONNECTED) {
    //

    BlynkEdgent.run();





    timerab.run();
  }
}







BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue = HIGH) {
    lock();
  }

}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue = HIGH) {
    unlock();
  }

}


BLYNK_WRITE(V7)
{
  acbutton = param.asInt(); // assigning incoming value from pin V1 to a variable



}

void headddd() {

  digitalWrite(relaypind, HIGH);
}
void hedd() {
  
  digitalWrite(relaypind, LOW);
  timeraa.setTimeout(20000, headddd);

  delay(10000);
  digitalWrite(relaypind, HIGH);
  headdallow = 0;
}
BLYNK_WRITE(V8)
{




  mistbutton = param.asInt(); // assigning incoming value from pin V1 to a variable
}


BLYNK_WRITE(V9)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue = HIGH) {
    if (headdallow == 1) {
      hedd();

      delay(100);


      tone(BUZZER_PIN, NOTE_D4, 200, BUZZER_CHANNEL);
      tone(BUZZER_PIN, NOTE_D5, 200, BUZZER_CHANNEL);
      tone(BUZZER_PIN, NOTE_D6, 200, BUZZER_CHANNEL);
      noTone(BUZZER_PIN, BUZZER_CHANNEL);




    }

    if (headdallow == 0) {

      tone(BUZZER_PIN, NOTE_D4, 200, BUZZER_CHANNEL);
      tone(BUZZER_PIN, NOTE_D5, 200, BUZZER_CHANNEL);
      tone(BUZZER_PIN, NOTE_D4, 200, BUZZER_CHANNEL);
      noTone(BUZZER_PIN, BUZZER_CHANNEL);
    }
  }

}












BLYNK_WRITE(V6)
{
  int actemp = param.asInt(); // assigning incoming value from pin V1 to a variable


}

void datasync() {

  Blynk.virtualWrite(V4, WiFi.RSSI());

  Blynk.virtualWrite(V15, analogRead(sensorpine) / 2017.7033);


  sensors.requestTemperatures(); 
  cartemp = sensors.getTempCByIndex(0);

  Blynk.virtualWrite(V5, cartemp);

  Blynk.virtualWrite(V13, acc);
  int but = digitalRead(sensorpina);
  if (but == HIGH) {
    Blynk.virtualWrite(V3, 0);

  } else {
    Blynk.virtualWrite(V3, 1);

  }



  Blynk.virtualWrite(V16, carmoving);
  Blynk.virtualWrite(V10, acbutton);


  Blynk.virtualWrite(V11, mistbutton);



  Blynk.virtualWrite(V12, headdallow);


}






BLYNK_CONNECTED() {
  // Synchronize time on connection
  rtc.begin();

}



void rfid() {

  int but = digitalRead(sensorpina);

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
    terminal.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    terminal.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
    terminal.flush();

  }
  content.toUpperCase();

  if (content.substring(1) == ACCESS_KEY && but == LOW) //change here the UID of the card/cards that you want to give access
  {
    lock();


    digitalWrite(led2pin, HIGH);

    delay(4000);

    digitalWrite(led2pin, LOW);

  }
  if (content.substring(1) == ACCESS_KEY && but == HIGH) //change here the UID of the card/cards that you want to give access
  {


    unlock();

    digitalWrite(led2pin, HIGH);
    delay(4000);
    digitalWrite(led2pin, LOW);

  }



  if (content.substring(1) == ACCESS_CARD && but == HIGH) //change here the UID of the card/cards that you want to give access
  {


    unlock();

    digitalWrite(led2pin, HIGH);
    delay(4000);
    digitalWrite(led2pin, LOW);

  }

  if (content.substring(1) == ACCESS_CARD && but == LOW) //change here the UID of the card/cards that you want to give access
  {

    lock();

    digitalWrite(led2pin, HIGH);
    delay(4000);
    digitalWrite(led2pin, LOW);

  }


}




















void unlock()
{
  oped++;

  digitalWrite(led2pin, HIGH);



  digitalWrite(relaypina, HIGH);
  digitalWrite(relaypinb, LOW);
  delay(200);
  digitalWrite(relaypina, HIGH);
  digitalWrite(relaypinb, HIGH);
  digitalWrite(led2pin, LOW);

}


void lock()
{

  oped++;
  digitalWrite(led2pin, HIGH);


  digitalWrite(relaypina, LOW);
  digitalWrite(relaypinb, HIGH);
  delay(200);
  digitalWrite(relaypina, HIGH);
  digitalWrite(relaypinb, HIGH);
  digitalWrite(led2pin, LOW);

}
