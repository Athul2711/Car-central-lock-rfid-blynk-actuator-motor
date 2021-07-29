#include <SimpleTimer.h>

#include <ESP8266WiFi.h>
#include <espnow.h>

#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
//
//#ifndef STASSID
  const char *ssid = "hlo123";
  const char *pass = "1231231234";

//#endif

bool r1 = 1;
bool r2 = 1;


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



bool atka = 0;
char ACCESS_KEY[] = "09 97 3D 59";
char ACCESS_CARD[] = "46 C6 24 52";

typedef struct struct_message {
  int dataa;
  int datab;
  int datac;
  unsigned long datad;
  unsigned long datae;

} struct_message;

struct_message myData;

struct_message incomingReadings;

uint8_t broadcastAddress[] = {0xDC, 0x4F, 0x22, 0x76, 0x27, 0xE4};



int but = 0;





#define SS_PIN D4
#define RST_PIN D3
#define relaypina D2
#define relaypinb D0
#define locksensor D1
#define LED D8

SimpleTimer timer;


















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












  wifi_promiscuous_enable(1);
  wifi_set_channel(1);
  wifi_promiscuous_enable(0);






  timer.setInterval(4000, clearall);
  timer.setInterval(10000, mfrcc);
  timer.setInterval(1300, datasend);

  timer.setInterval(1500, corr);

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
  myData.datab = acc;
  myData.datac = analogRead(A0);
  myData.datad = oped;
  myData.datae = true;
  esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

}








void corr(){








  int atkb = 1;

  int buu = analogRead(A0);
  if (buu > 200 && atkb == 1 && atkbb == 1) {
    acc = 1;
    atkbb = 0;
    atkb = 0;
//ESP.setcpufreq(80);


    
  }


  if (buu < 100 && atkb == 1 && atkbb == 0) {
    atkbb = 1;
    atkb = 0;
    acc = 0;
    unlock();

  }





}







void loop() {
  // put your main code here, to run repeatedly:
  timer.run();










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
