

unsigned long lastflash;
int RPM;
void ICACHE_RAM_ATTR sens() {
  RPM++;
}
int p, k, reddd, bba;
unsigned long previousMillis = 0;        // will store last time LED was updated
int rpmnewa;
int timerid;
#include <SimpleTimer.h>
float rpmnew = 0;
#include <ESP8266WiFi.h>
#include <espnow.h>

#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
bool a0;
//#ifndef STASSID
const char *ssid = "hlo123";
const char *pass = "1231231234";
bool carstart = false;
//#endif
int buu;
bool r1 = 1;
int i = 0, q;
bool r2 = 1;
int rc, gc, bc;
#include <WS2812FX.h>

#define LED_PIN    14  // digital pin used to drive the LED strip
#define LED_COUNT 21  // number of LEDs on the strip

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int ls = 0;
int seecrr = 0;

bool serp = 1;
bool acc = 0;
unsigned long oped = 0;
bool atkbb = 0;
bool carmoving = 0;
unsigned long lockcode = 0;
unsigned long unlockcode = 0;

bool dooropen = 0;
unsigned long locksucesscode = 0;
unsigned long unlocksucesscode = 0;

int remoteunlockcode = 0;
int remotelockcode = 0;


int hourr = 0;
bool atka = 0;
char ACCESS_KEY[] = "09 97 3D 59";
char ACCESS_CARD[] = "46 C6 24 52";

typedef struct struct_message {
  int dataa;
  int datab;
  int datac;
  unsigned long datad;
  unsigned long datae;
  int dataf;
  float x;
  float y;
  float z;
} struct_message;

struct_message myData;

struct_message incomingReadings;

uint8_t broadcastAddress[] = {0xDC, 0x4F, 0x22, 0x76, 0x27, 0xE4};


float xg = 0, zg = 0;
int but = 0;
int yg = 0;




#define SS_PIN D4
#define RST_PIN D3
#define relaypina D2
#define relaypinb D0
#define locksensor D1
#define LED D8

SimpleTimer timer;

SimpleTimer timera;

















void secret() {




  if (digitalRead(D6) == 1) {
    digitalWrite(D8, HIGH);
    delay(190);
    digitalWrite(D8, LOW);
    Serial.print(seecrr);

    seecrr++;
  }



  if (digitalRead(D6) == 0) {

    if (seecrr == 4) {
      digitalWrite(D8, HIGH);


      lockandunlock();







    }



    seecrr = 0;

  }


}




void setup() {

























  pinMode(relaypina, OUTPUT);
  pinMode(relaypinb, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(relaypina, HIGH);
  digitalWrite(relaypinb, HIGH);
  digitalWrite(LED, LOW);
  pinMode(A0, INPUT);
  pinMode(locksensor, INPUT);
  pinMode(D6, INPUT);
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  //  WiFi.begin(ssid, pass);

  pinMode(D7, INPUT);

  timerid = timera.setInterval(120, rpmread);
  timera.disable(timerid);



  ws2812fx.init();
  ws2812fx.setBrightness(255);

  // parameters: index, start, stop, mode, color, speed, reverse
  ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x000000u, 1000, false); // segment 0 is leds 0 - 9
  ws2812fx.setSegment(1, 9, 21, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19
  ws2812fx.setCustomMode(myCustomEffect);

  ws2812fx.start();






  wifi_promiscuous_enable(1);
  wifi_set_channel(1);
  wifi_promiscuous_enable(0);






  timer.setInterval(4000, clearall);
  timer.setInterval(10000, mfrcc);
  timer.setInterval(1300, datasend);

  timer.setInterval(700, corr);

  timer.setInterval(800, alll);
  timer.setInterval(1000, secret);
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);

  esp_now_register_send_cb(OnDataSent);
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_COMBO, 1, NULL, 0);



  esp_now_register_recv_cb(OnDataRecv);






}







void datasend() {
  but = digitalRead(locksensor);
  myData.dataa = but;
  myData.datab = carstart;
  myData.datac = analogRead(A0);
  myData.datad = oped;
  myData.datae = true;
  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

}


void rpmread() {

  detachInterrupt(digitalPinToInterrupt(D7));


  unsigned long currentMillis = millis();
  unsigned long timepass = currentMillis - previousMillis;
  float truetimepass = timepass / 1000.0;
  previousMillis = currentMillis;

  rpmnew = (RPM) / truetimepass;  //here we used fan which has 3 wings



  //  Serial.println(RPM);
  //  Serial.println(timepass);
  //  Serial.println(truetimepass);

  RPM = 0;


  rpmnewa = rpmnew * 30;



  //  Serial.println(rpmnewa);







  attachInterrupt(digitalPinToInterrupt(D7), sens, CHANGE);

}


uint16_t myCustomEffect(void) { // random chase

  if (ls != 2) {

    if (i > 8) {
      ws2812fx.setPixelColor(i, rc, gc, bc);


      i--;
      bba = 100;
    }


  }


  if (ls == 2) {
    bba = 110;
    p = 0;

    if (hourr > 17) {
      //
      if (rpmnewa < 1300) {
        rc = 0;
        gc = 0;
        bc = 50;
      }
      else {
        bc = 0;
        rc = map(rpmnewa, 1000, 5800, 1, 50);
        gc = map(rpmnewa, 1000, 5800, 50, 1);

      }
    } else {

      if (rpmnewa < 1100) {
        rc = 0;
        gc = 0;
        bc = 255;
      }
      else {

        //        if(rpmnewa <= 3300){
        rc = map(rpmnewa, 700, 5800, 1, 255);
        //        gc = 255;
        //        }else{

        gc = map(rpmnewa, 700, 5800, 255, 1);
        //        rc = 255;

        //        }

        bc = 0;
      }

    }

    int pr = 0, pg = 0, pb = 0, la = 0, ra = 0;

    //    int turevalg = (sqrt((xg*xg)+(yg*yg)+(zg*zg))*255);
    //    pr = turevalg;
    //     pb = map(turevalg,0,180,255,0);

    if (yg >= 0) {

      ra = yg * 65;
      la = 0;

    } else if (yg <= 0 ) {

      la = yg * -65;
      ra = 0;

    }

    //
    //    if (rpmnewa < 1100) {
    //      pr = 0;
    //      pg = 0;
    //      pb = 255;
    //    }
    //    else {
    //      pr = map(rpmnewa, 1000, 5800, 1, 255);
    //      pg = map(rpmnewa, 1000, 5800, 255, 1);
    //      pb = 0;
    //
    //    }
    if (la > 100) {
      ws2812fx.setPixelColor(3, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(3, 0, xg, 255);


    }


    if (la > 200) {
      ws2812fx.setPixelColor(2, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(2, 0, xg, 255);


    }

    if (la > 300) {
      ws2812fx.setPixelColor(1, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(1, 0, xg, 255);


    }

    if (la > 400) {
      ws2812fx.setPixelColor(0, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(0, 0, xg, 255);


    }

    if (ra > 100) {
      ws2812fx.setPixelColor(5, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(5, 0, xg, 255);


    }


    if (ra > 200) {
      ws2812fx.setPixelColor(6, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(6, 0, xg, 255);


    }

    if (ra > 300) {
      ws2812fx.setPixelColor(7, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(7, 0, xg, 255);


    }

    if (ra > 400) {
      ws2812fx.setPixelColor(8, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(8, 0, xg, 255);


    }

    ws2812fx.setPixelColor(4, 0, xg, 255);





    for (k = 20; k > 8; k--) {

      //
      //      if (p > 4 && p <= 8) {
      //
      //      }
      //
      //



      //
      //      if (la >= ((250 * ((3-p)+1)))) {




      //if(




      //      }

      //
      //
      //      if (la < ((250 * ((3-p)+1)))) {
      //
      //        ws2812fx.setPixelColor((3-p), 0, 100, 255);
      //


      //      }




      //      }

      p++;

      if (rpmnewa >= ((500 * p) + 150)) {





        ws2812fx.setPixelColor(k, rc, gc, bc);



      }
      if (rpmnewa < ((500 * p) - 250)) {
        if (hourr > 17) {
          ws2812fx.setPixelColor(k, 0, 50, 0);

        }
        else {
          ws2812fx.setPixelColor(k, 0, 255, 0);



        }
      }





    }






  }

  return bba; // return the delay until the next animation step (in msec)



}

void offled() {
  if (ls == 3) {
    ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x000000u, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 21, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19
    ls = 0;
  }
  if (ls == 2) {

    i = 21;

    ws2812fx.setSegment(0,  0,  8, FX_MODE_CUSTOM, 0x00FF00u, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 21, FX_MODE_CUSTOM,  0x000000u, 1000, false); // segment 1 is leds 10 - 19
  }

  if (ls == 1) {

    i = 21;
    rc = 52;
    gc = 86;
    bc = 149;


    ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x34568bu, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 21, FX_MODE_CUSTOM,  0x000000u, 1000, false); // segment 1 is leds 10 - 19

    timer.setTimeout(120000, offledacc);
  }




}
void offledacc() {
  if (ls == 1 && carstart == false) {
    ls = 0;

    ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x000000u, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 21, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19

  }


}
void corr() {





  if (dooropen == 0 && carstart == 1) {


    ws2812fx.setSegment(0,  0,  8, FX_MODE_BLINK, 0xFFFF00u, 500, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 21, FX_MODE_BLINK,  0xFFFF00u, 500, false); // segment 1 is leds 10 - 19

  }



  if (dooropen == false && a0 == true) {
    a0 = false;


    ws2812fx.setSegment(0,  0,  8, FX_MODE_BREATH, 0xFFFF00u, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 21, FX_MODE_BREATH,  0xFFFF00u, 1000, false); // segment 1 is leds 10 - 19
    timer.setTimeout(25000, offled);
    if (ls == 0) {
      ls = 3;
    }
  }


  if (dooropen == true && a0 == false) {
    a0 = true;
    if (carstart == 1) {
      offled();

    }
  }




  int atkb = 1;

  buu = analogRead(A0);

  if (buu > 650 && carstart == false && acc == 1) {
    carstart = true;
    attachInterrupt(digitalPinToInterrupt(D7), sens, CHANGE);

    i = 21;

    if (hourr > 17) {
      rc = 0;
      gc = 33;
      bc = 0;
    }
    else {
      rc = 0;
      gc = 255;
      bc = 0;
    }
    ws2812fx.setSegment(0,  0,  8, FX_MODE_CUSTOM, 0x00FF00u, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 21, FX_MODE_CUSTOM,  0x000000u, 1000, false); // segment 1 is leds 10 - 19
    ls = 2;



  }


  if (buu > 200 && atkb == 1 && atkbb == 1) {
    acc = 1;
    atkbb = 0;
    atkb = 0;
    //ESP.setcpufreq(80);

    i = 21;
    rc = 52;
    gc = 86;
    bc = 149;


    ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x34568bu, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 21, FX_MODE_CUSTOM,  0x000000u, 1000, false); // segment 1 is leds 10 - 19
    timera.enable(timerid);

    ls = 1;

    timer.setTimeout(120000, offledacc);

  }


  if (buu < 100 && atkb == 1 && atkbb == 0) {
    delay(500);
    buu = analogRead(A0);
    if (buu < 100) {

      atkbb = 1;
      atkb = 0;
      acc = 0;
      unlock();
      carstart = false;


      timera.disable(timerid);

      detachInterrupt(digitalPinToInterrupt(D7));


      ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x000000u, 1000, false); // segment 0 is leds 0 - 9
      ws2812fx.setSegment(1, 9, 21, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19


      ls = 0;
    }
  }





}







void loop() {
  // put your main code here, to run repeatedly:
  timer.run();
  timera.run();



  ws2812fx.service();







}


void alll() {



























  if (lockcode > locksucesscode) {
    locksucesscode = lockcode;

    Serial.print(locksucesscode);


    lock();

  }



  if (remoteunlockcode == 1) {

    remoteunlockcode = 0;
    unlock();



  }



  if (remotelockcode == 1) {

    remotelockcode = 0;



    lock();


  }







  if (unlockcode > unlocksucesscode) {
    unlocksucesscode = unlockcode;

    Serial.print(unlocksucesscode);

    unlock();
  }





  if (carmoving == 1 && r1 == 1) {
    r1 = 0;
    lock();
  }



  if (carmoving == 0 && r1 == 0) {
    r1 = 1;
  }










  int  atk = 1;

  int but = digitalRead(locksensor);
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


































}




void mfrcc()
{



  if (ls == 0 && buu > 200) {



    ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x000000u, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 21, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19


  }

  digitalWrite(relaypina, HIGH);
  digitalWrite(relaypinb, HIGH);
  digitalWrite(LED, LOW);
}








void clearall()
{
  r2 = 1;
}

void unlock()
{

  if (r2 == 1) {
    r2 = 0;
    oped++;
    digitalWrite(LED, HIGH);

    Serial.print("unlocked");

    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, LOW);
    delay(200);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
    digitalWrite(LED, LOW);

  }
}

void lock()
{

  if (r2 == 1) {
    r2 = 0;

    oped++;
    digitalWrite(LED, HIGH);

    Serial.print("locked");

    digitalWrite(relaypina, LOW);
    digitalWrite(relaypinb, HIGH);
    delay(200);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);
    digitalWrite(LED, LOW);
  }
}


void lockandunlock()
{

  if (r2 == 1) {
    r2 = 0;

    oped++;
    digitalWrite(LED, HIGH);

    Serial.print("locked");

    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, LOW);
    delay(200);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);


    delay(800);

    digitalWrite(relaypina, LOW);
    digitalWrite(relaypinb, HIGH);
    delay(200);
    digitalWrite(relaypina, HIGH);
    digitalWrite(relaypinb, HIGH);





    digitalWrite(LED, LOW);
  }
}





void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&incomingReadings, incomingData, sizeof(incomingReadings));
  //  Serial.print("Bytes received: ");
  //  Serial.println(len);




  int unk = incomingReadings.datab;   //secret



  if (unk == false) {
    carmoving = incomingReadings.dataa;   // mpu6050


    dooropen = incomingReadings.datac;   //door

    lockcode = incomingReadings.datad;  //lock
    unlockcode = incomingReadings.datae;  ///unlock
    hourr = incomingReadings.dataf;
    xg = incomingReadings.x;
    yg = incomingReadings.y;
    //    zg = incomingReadings.z;
    //    Serial.println("start");
    //        Serial.println(carmoving);
    //    Serial.println(dooropen);
    //    Serial.println(lockcode);
    //    Serial.println(unlockcode);
    //    Serial.println(hourr);
    //    Serial.println(xg);
    //    Serial.println(yg);
    //    Serial.println(zg);

  }



  if (unk == true) {




    remotelockcode = incomingReadings.datad;  //lock
    remoteunlockcode = incomingReadings.datae;  ///unlock




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
