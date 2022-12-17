int ri, gi, bi;
int corai = 0, coraii = 0, colaii = 0, colai = 0;
#include <Arduino.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
unsigned long lastflash;
int RPM;
void ICACHE_RAM_ATTR sens() {
  RPM++;
}
int p, k, reddd, bba;
unsigned long previousMillis = 0;        // will store last time LED was updated
int rpmnewa;
#include <SimpleTimer.h>
float rpmnew = 0;
#include <ESP8266WiFi.h>
#include <espnow.h>
int countflag=0;
int timerid;
unsigned long later=0,current=0;
int currentTimee=0;
unsigned long prevTimee=0;

int xrr, xgg;

//#include <WiFiClient.h>
//#include <ESP8266WebServer.h>
//#include <ESP8266mDNS.h>
//#include <ESP8266HTTPUpdateServer.h>
bool a0;
//#ifndef STASSID
const char *ssid = "hlo12";
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
#define LED_COUNT 34  // number of LEDs on the strip

AsyncWebServer server(80);






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

bool dooropen = 1;
unsigned long locksucesscode = 0;
unsigned long unlocksucesscode = 0;

int remoteunlockcode = 0;
int remotelockcode = 0;


int hourr = 0, minutee = 0, secondd = 0;;
bool atka = 0;
char ACCESS_KEY[] = "09 97 3D 59";
char ACCESS_CARD[] = "46 C6 24 52";

typedef struct struct_message {
  int dataa = 2002;
  int datab = 0;
  int datac = 1;
  unsigned long datad = 0;
  unsigned long datae = 0;
  int dataf = 0;
  int datag = 0;
  int datah = 0;
  float x = 0;
  float y = 0;
  float z = 0;
  int lightcode = 0;
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










String readBME280Temperature() {
  return String(rpmnewa);
}


String readBME280Humidity() {
  return String(yg);

}

String readBME280Pressure() {
  return String(myData.datac);



}







void secret() {




  if (digitalRead(D6) == 1 && acc == 0 && seecrr < 9) {
    digitalWrite(D8, HIGH);
    delay(190);
    digitalWrite(D8, LOW);
    Serial.print(seecrr);
//
//    ws2812fx.setSegment(0, 0, 8, FX_MODE_STATIC,  0xFFFFFFu, 50, false); // segment 1 is leds 10 - 19
//    ws2812fx.setSegment(1, 9, 20, FX_MODE_STATIC,  0xFFFFFFu, 50, false); // segment 1 is leds 10 - 19
//    ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0xFFFFFFu, 50, true); // segment 1 is leds 10 - 19



//    timer.setTimeout(300, offled);

    if (ls == 0) {
      ls = 3;
    }
    seecrr++;
  }



  if (digitalRead(D6) == 0 && acc == 0) {

    if (seecrr == 4) {
      digitalWrite(D8, HIGH);


      lockandunlock();







    }



    seecrr = 0;

  }


}




void setup() {

  //
  //
  //  if (!SPIFFS.begin()) {
  //    Serial.println("An Error has occurred while mounting SPIFFS");
  //    return;
  //  }
  //
  //
  //
  //
  //
  //









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
  pinMode(D3, INPUT_PULLUP);

  WiFi.mode(WIFI_STA);
  //  WiFi.begin(ssid, pass);
  WiFi.disconnect();

    pinMode(D7, OUTPUT);
    digitalWrite(D7,HIGH);



  timerid = timera.setInterval(170, rpmread);
  timera.disable(timerid);


  ws2812fx.init();
  ws2812fx.setBrightness(255);

  // parameters: index, start, stop, mode, color, speed, reverse
  ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x000000u, 1000, false); // segment 0 is leds 0 - 9
  ws2812fx.setSegment(1, 9, 20, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19
  ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19

  ws2812fx.setCustomMode(myCustomEffect);

  ws2812fx.start();






  wifi_promiscuous_enable(1);
  wifi_set_channel(1);
  wifi_promiscuous_enable(0);



  timer.setInterval(750, corr);

  timer.setInterval(300000, mfrccc);


  timer.setInterval(4000, clearall);
  timer.setInterval(10000, mfrcc);
  
  timer.setInterval(1300, datasend);

  timer.setInterval(850, alll);
  timer.setInterval(1000, secret);
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);

  esp_now_register_send_cb(OnDataSent);
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_COMBO, 1, NULL, 0);



  esp_now_register_recv_cb(OnDataRecv);


  Serial.println(WiFi.localIP());

  //
  //
  //  // Route for root / web page
  //  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
  //    request->send(SPIFFS, "/index.html");
  //  });
  //  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest * request) {
  //    request->send_P(200, "text/plain", readBME280Temperature().c_str());
  //  });
  //  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest * request) {
  //    request->send_P(200, "text/plain", readBME280Humidity().c_str());
  //  });
  //  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest * request) {
  //    request->send_P(200, "text/plain", readBME280Pressure().c_str());
  //  });
  //
  //  // Start server
  //  server.begin();
  //
  //







}






void rpmread() {

  detachInterrupt(digitalPinToInterrupt(D3));
  unsigned long currentMillis = millis();
  unsigned long timepass = currentMillis - previousMillis;
  float truetimepass = timepass / 1000.0;
  previousMillis = currentMillis;
  rpmnew = (RPM) / truetimepass;  //here we used fan which has 3 wings
  RPM = 0;
  rpmnewa = rpmnew * 30;
  attachInterrupt(digitalPinToInterrupt(D3), sens, CHANGE);

}

void datasend() {
  if(incomingReadings.dataa !=2002){
    
  but = digitalRead(locksensor);
  myData.dataa = but;
  myData.datab = carstart;
  myData.datac = analogRead(A0);
  myData.datad = oped;
  myData.datae = true;
  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
  ws2812fx.setBrightness(255);

  
  }else{
if(carstart == 1){
  ws2812fx.setBrightness(255);
}else{
    ws2812fx.setBrightness(0);

}



    
  }



  
}



uint16_t myCustomEffect(void) { // random chase


  if (ls != 2) {

    if (i > 8) {
      ws2812fx.setPixelColor(i, rc, gc, bc);






      i--;
      bba = 100;
    } else {
      int reve = 0;

      for (int yy = 20; yy >= 9; yy--) {

        int buuaa = (analogRead(A0) - 495);
        Serial.println(buuaa);
        if (buuaa > ((7 * reve) ) + 5) {
          ws2812fx.setPixelColor(yy, rc, gc, bc);
        }


        if (buuaa < ((7 * reve) ) - 5) {
          ws2812fx.setPixelColor(yy, rc, 0, 0);
        }

        reve++;
      }
    }

  }


  if (ls == 2) {













    
    bba = 150;
    p = 0;
    //
    //    //      xgg = 255;
    //    //      xrr = 0;
    //    //
    //    if (rpmnewa < 1300) {
    //      rc = 0;
    //      gc = 0;
    //      bc = 50;
    //    }
    //    else {
    //      bc = 0;
    //      //        rc = map(rpmnewa, 1000, 5999, 1, 50);
    //      rc = 50;
    //      gc = map(rpmnewa, 1000, 5999, 50, 1);
    //
    //    }
    //  } else {



    if (hourr > 17 || hourr < 6) {

      rc = 50;
      gc = map(rpmnewa, 700, 5999, 35, 0);
      bc = map(rpmnewa, 700, 5999, 60, 0);


    } else {



      rc = 250;

      gc = map(rpmnewa, 700, 5999, 240, 0);
      bc = map(rpmnewa, 700, 5999, 255, 0);


    }


    if (rpmnewa < 1100) {
      rc = 0;
      gc = 0;
      bc = 255;
    }


    //
    //  xgg = 0;
    //  xrr = 255;
    int la = 0, ra = 0;

    //    int turevalg = (sqrt((xg*xg)+(yg*yg)+(zg*zg))*255);
    //    pr = turevalg;
    //     pb = map(turevalg,0,180,255,0);

    if (yg >= 0) {

      la = yg * 50;
      ra = 0;

    } else if (yg <= 0 ) {

      ra = yg * -50;
      la = 0;

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
      ws2812fx.setPixelColor(3,  146, 168, 209);


    }


    if (la > 250) {
      ws2812fx.setPixelColor(2, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(2,  146, 168, 209);


    }

    if (la > 400) {
      ws2812fx.setPixelColor(1, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(1,  146, 168, 209);


    }

    if (la > 600) {
      ws2812fx.setPixelColor(0, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(0,  146, 168, 209);


    }

    if (ra > 100) {
      ws2812fx.setPixelColor(5, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(5,  146, 168, 209);


    }


    if (ra > 250) {
      ws2812fx.setPixelColor(6, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(6,  146, 168, 209);


    }

    if (ra > 400) {
      ws2812fx.setPixelColor(7, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(7,  146, 168, 209);


    }

    if (ra > 600) {
      ws2812fx.setPixelColor(8, 255, 0, 0);

    } else {
      ws2812fx.setPixelColor(8,  146, 168, 209);


    }

    ws2812fx.setPixelColor(4,  146, 168, 209);





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

      if (rpmnewa >= ((500 * (p+1)) + 300)) {





        ws2812fx.setPixelColor(k, rc, gc, bc);



      }
      if (rpmnewa < ((500 * (p+1))  -200)) {
        if (hourr > 17) {
          ws2812fx.setPixelColor(k, 52, 86, 139);

        }
        else {
          ws2812fx.setPixelColor(k, 23, 38, 61);



        }
      }





    }
    if (hourr > 17) {


        corai = map((constrain(ra,300,1200)), 300, 1200, 230, 0);
        coraii = map((constrain(ra,300,1200)), 300, 1200, 255, 0);
        colai = map((constrain(la,300,1200)), 300, 1200, 230, 0);
        colaii = map((constrain(la,300,1200)), 300, 1200, 255, 0);

        

      for (k = 21; k <= 24; k++) {


          ws2812fx.setPixelColor(k, 48, (corai/5), (coraii/5));



      }






      for (k = 25; k <= 28; k++) {




          ws2812fx.setPixelColor(k, 48, (colai/5), (colaii/5));





        //          ws2812fx.setPixelColor(k, 23, 38, 61);




      }

      for (k = 29; k <= 30; k++) {



          ws2812fx.setPixelColor(k, 240, colai, colaii);





      }

      for (k = 31; k <= 32; k++) {


          ws2812fx.setPixelColor(k, 240, corai, coraii);




      }

    }else{
        for(k=21;k<=32;k++){

                    ws2812fx.setPixelColor(k, 0, 0, 0);

        }

      
    }


  }
  return bba; // return the delay until the next animation step (in msec)




}
void offled() {
  if (ls != 1 && ls != 2) {
    ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x000000u, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 20, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19

    ls = 0;
  }
  if (ls == 2) {

    i = 20;

    ws2812fx.setSegment(0,  0,  8, FX_MODE_CUSTOM, 0x00FF00u, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 20, FX_MODE_CUSTOM,  0x000000u, 1000, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_CUSTOM,  0x000000u, 1000, false); // segment 1 is leds 10 - 19

  }

  if (ls == 1) {

    i = 20;
    rc = 52;
    gc = 86;
    bc = 149;

    if (hourr > 17) {
      ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0x305082u, 1000, false); // segment 1 is leds 10 - 19
      ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x305082u, 1000, false); // segment 0 is leds 0 - 9

    } else {
      ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x34568bu, 1000, false); // segment 0 is leds 0 - 9

      ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19

    }
    ws2812fx.setSegment(1, 9, 20, FX_MODE_CUSTOM,  0x000000u, 1000, false); // segment 1 is leds 10 - 19

    timer.setTimeout(120000, offledacc);
  }




}
void offledacc() {
  if (ls == 1 && carstart == false) {
    ls = 0;

    ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x000000u, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 20, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19

  }


}
void corr() {





  if (dooropen == 0 && carstart == 1) {


    ws2812fx.setSegment(0,  0,  8, FX_MODE_BLINK, 0xFF6F61u, 500, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 20, FX_MODE_BLINK,  0xFF6F61u, 500, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_BLINK,  0xFF6F61u, 500, false); // segment 1 is leds 10 - 19
  }



  if (dooropen == false && a0 == true) {
    a0 = false;


    ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x885B95u, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 20, FX_MODE_STATIC,  0x885B95u, 1000, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0x885B95u, 1000, false); // segment 1 is leds 10 - 19

    timer.setTimeout(25000, offled);
    if (ls == 0) {
      ls = 3;
    }
  }


  if (dooropen == true && a0 == false) {
    a0 = true;
    ws2812fx.setSegment(0, 0, 8, FX_MODE_BREATH,  0xFFFF00u, 1000, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(1, 9, 20, FX_MODE_BREATH,  0xFFFF00u, 1000, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_BREATH,  0xFFFF00u, 1000, false); // segment 1 is leds 10 - 19

    if (carstart == 1) {
      offled();

    }
    timer.setTimeout(25000, offled);

    if (ls == 0) {
      ls = 3;
    }

  }




  int atkb = 1;

    if(countflag > 15){
    buu = analogRead(A0);
    }else{

      buu = 0;
      countflag++;
    }
//  buu = analogRead(A0);

  if (buu > 580 && carstart == false && acc == 1) {
    //      WiFi.begin(ssid, pass);
later = millis();

    carstart = true;
    attachInterrupt(digitalPinToInterrupt(D3), sens, CHANGE);

    i = 20;
    timera.enable(timerid);


    ws2812fx.setSegment(2, 21, 34, FX_MODE_CUSTOM,  0x000000u, 1000, false); // segment 1 is leds 10 - 19




    ws2812fx.setSegment(0,  0,  8, FX_MODE_CUSTOM, 0x00FF00u, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 20, FX_MODE_CUSTOM,  0x000000u, 1000, false); // segment 1 is leds 10 - 19
    ls = 2;



  }


  if (buu > 200 && atkb == 1 && atkbb == 1) {
    acc = 1;
    atkbb = 0;
    atkb = 0;
    //ESP.setcpufreq(80);

    i = 20;
    rc = 52;
    gc = 86;
    bc = 149;

    if (hourr > 17) {
      ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0x305088u, 1000, false); // segment 1 is leds 10 - 19
      ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x305088u, 1000, false); // segment 0 is leds 0 - 9

    } else {
      ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x34568bu, 1000, false); // segment 0 is leds 0 - 9

      ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19

    }
    ws2812fx.setSegment(1, 9, 20, FX_MODE_CUSTOM,  0x000000u, 1000, false); // segment 1 is leds 10 - 19

    ls = 1;

    timer.setTimeout(120000, offledacc);

  }


  if (buu < 100 && atkb == 1 && atkbb == 0) {
    delay(500);
    if(countflag > 15){
    buu = analogRead(A0);
    }else{
      countflag++;

      buu = 0;
    }
    if (buu < 100) {

      atkbb = 1;
      atkb = 0;
      acc = 0;
      unlock();
      carstart = false;
      rpmnewa = 0;

      timera.disable(timerid);

      detachInterrupt(digitalPinToInterrupt(D3));

      ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19

      ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x000000u, 1000, false); // segment 0 is leds 0 - 9
      ws2812fx.setSegment(1, 9, 20, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19


      ls = 0;

      //
      //
      //  wifi_promiscuous_enable(1);
      //  wifi_set_channel(1);
      //  wifi_promiscuous_enable(0);




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

void mfrccc(){
current = millis();
if(current < later){

  later = current;
}
if((current-later)> 80000000){
    digitalWrite(D7,LOW);

  
}
//
//if((current-later)> 120000){
//    digitalWrite(D7,LOW);
//
//  
//}



  
if(acc == 0){
  
    ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x000000u, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 20, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19

}




  
}


void mfrcc()
{



  if (ls == 0 && buu < 200) {



    ws2812fx.setSegment(0,  0,  8, FX_MODE_STATIC, 0x000000u, 1000, false); // segment 0 is leds 0 - 9
    ws2812fx.setSegment(1, 9, 20, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0x000000u, 1000, false); // segment 1 is leds 10 - 19


  }

  digitalWrite(relaypina, HIGH);
  digitalWrite(relaypinb, HIGH);
  digitalWrite(LED, LOW);




  
}








void clearall()
{

if((millis() - prevTimee) > 201600000){

  //
}

  
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

if(carstart!=1){

    ws2812fx.setSegment(0, 0, 8, FX_MODE_STATIC,  0x00FF00u, 100, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(1, 9, 20, FX_MODE_STATIC,  0x00FF00u, 100, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0x00FF00u, 100, true); // segment 1 is leds 10 - 19

}

    timer.setTimeout(1000, offled);
    timer.setTimeout(1500, offled);

    if (ls == 0) {
      ls = 3;
    }
  }
}
void locktrue(){

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
  
    timer.setTimeout(15000, offled);

    if (ls == 0) {
      ls = 3;
    }
}
void lock()
{
  if(dooropen == false){
    timer.setTimeout(15000, locktrue);

if(carstart!=1){

    ws2812fx.setSegment(0, 0, 8, FX_MODE_FADE,  0xFFFF00u, 400, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(1, 9, 20, FX_MODE_FADE,  0xFFFF00u, 400, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_FADE,  0xFFFF00u, 400, false); // segment 1 is leds 10 - 19

}

    timer.setTimeout(15000, offled);

    if (ls == 0) {
      ls = 3;
    }


    
  }else{
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
    
if(carstart!=1){

    ws2812fx.setSegment(0, 0, 8, FX_MODE_STATIC,  0xFF0000u, 100, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(1, 9, 20, FX_MODE_STATIC,  0xFF0000u, 100, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0xFF0000u, 100, true); // segment 1 is leds 10 - 19
}
    

    timer.setTimeout(1000, offled);
    timer.setTimeout(1500, offled);

    if (ls == 0) {
      ls = 3;
    }
  }
  }
}


void lockandunlock()
{

  if (r2 == 1) {
    r2 = 0;

    oped++;
    digitalWrite(LED, HIGH);

    ws2812fx.setSegment(0, 0, 8, FX_MODE_RAINBOW,  0xFF0000u, 100, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(1, 9, 20, FX_MODE_RAINBOW,  0xFF0000u, 100, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_RAINBOW,  0xFF0000u, 100, true); // segment 1 is leds 10 - 19


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



    ws2812fx.setSegment(0, 0, 8, FX_MODE_STATIC,  0xFF0000u, 100, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(1, 9, 20, FX_MODE_STATIC,  0xFF0000u, 100, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0xFF0000u, 100, true); // segment 1 is leds 10 - 19

    

    timer.setTimeout(300, offled);
    timer.setTimeout(600, offled);

    if (ls == 0) {
      ls = 3;
    }
    seecrr++;
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
    minutee = incomingReadings.datag;
    secondd = incomingReadings.datah;

    //
    //    xg = incomingReadings.x;
    //    if(xg > 255){
    //      xg = 255;
    //    }
    //xrr = xg;
    //xgg =map(xg,0,255,255,0);


    yg = incomingReadings.y;
    zg = incomingReadings.z;
    //        Serial.println("start");
    //        Serial.println(carmoving);
    //        Serial.println(dooropen);
    //        Serial.println(lockcode);
    //        Serial.println(unlockcode);
    //        Serial.println(hourr);
    //                Serial.println(minutee);
    //        Serial.println(secondd);
    //
    //        Serial.println(xg);
    //        Serial.println(yg);
    //        Serial.println(zg);

  }



  if (unk == true) {




    remotelockcode = incomingReadings.datad;  //lock
    remoteunlockcode = incomingReadings.datae;  ///unlock




  }





  if (unk == 6) {
    
    ws2812fx.setSegment(0, 0, 8, FX_MODE_COMET,  0xFF0000u, 1100, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(1, 9, 20, FX_MODE_COMET,  0xFF0000u, 1100, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_COMET,  0xFF0000u, 1100, false); // segment 1 is leds 10 - 19



    timer.setTimeout(1200, offled);

    if (ls == 0) {
      ls = 3;
    }

  }

  if (unk == 7) {
    
    ws2812fx.setSegment(0, 0, 8, FX_MODE_COMET,  0x00FF00u, 1100, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(1, 9, 20, FX_MODE_COMET,  0x00FF00u, 1100, true); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_COMET,  0x00FF00u, 1100, false); // segment 1 is leds 10 - 19



    timer.setTimeout(1200, offled);

    if (ls == 0) {
      ls = 3;
    }

  }

  if (unk == 8) {
    
    ws2812fx.setSegment(0, 0, 8, FX_MODE_COMET,  0x0000FFu, 1100, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(1, 9, 20, FX_MODE_COMET,  0x0000FFu, 1100, true); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_COMET,  0x0000FFu, 1100, false); // segment 1 is leds 10 - 19



    timer.setTimeout(1200, offled);

    if (ls == 0) {
      ls = 3;
    }

  }

  if (unk == 9) {
    
    ws2812fx.setSegment(0, 0, 8, FX_MODE_COMET,  0xFFFF00u, 1100, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(1, 9, 20, FX_MODE_COMET,  0xFFFF00u, 1100, true); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_COMET,  0xFFFF00u, 1100, false); // segment 1 is leds 10 - 19



    timer.setTimeout(1200, offled);

    if (ls == 0) {
      ls = 3;
    }

  }

  if (unk == 10) {
    
    ws2812fx.setSegment(0, 0, 8, FX_MODE_STATIC,  0xFFFFFFu, 900, false); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(1, 9, 20, FX_MODE_STATIC,  0xFFFFFFu, 900, true); // segment 1 is leds 10 - 19
    ws2812fx.setSegment(2, 21, 34, FX_MODE_STATIC,  0xFFFFFFu, 900, false); // segment 1 is leds 10 - 19



    timer.setTimeout(1000, offled);

    if (ls == 0) {
      ls = 3;
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
