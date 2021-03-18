//Technical Romboz   www.youtube.com/c/technicalromboz

//Blynk Fire Alarm Notification

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;

char auth[] = "8de4b3def8fe43f7a32558e047888838"; //Auth code sent via Email

char ssid[] = "technicalromboz"; //Wifi name

char pass[] = "hacker.io";  //Wifi Password

int flag=0;

void notifyOnFire()

{

  int isButtonPressed = digitalRead(D1);

  if (isButtonPressed==1 && flag==0) {

    Serial.println("Fire in the House");

    Blynk.notify("Alert:- Fire in the House");

    flag=1;

  }

  else if (isButtonPressed==0)

  {

    flag=0;

  }

}

void setup()

{

Serial.begin(9600);

Blynk.begin(auth, ssid, pass);

pinMode(D1,INPUT_PULLUP);

timer.setInterval(1000L,notifyOnFire); 

}

void loop()

{

  Blynk.run();

  timer.run();

}
