
/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL63cVq0c4z"
#define BLYNK_TEMPLATE_NAME "smartSwitch"
#define BLYNK_AUTH_TOKEN "zdhIYdN9K6AIcJYN8iB-oS2MDcer_sAK"

/* Comment this out to disable prints and save space */
//#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


BlynkTimer timer;

const int relay = 3;
const int connectedLed = 1;

char ssid[] = "ssid";
char pass[] = "pass";

bool first = true;

void setup()
{

//  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);

  pinMode(connectedLed, OUTPUT);
  digitalWrite(connectedLed, LOW);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 8080);
  
  timer.setInterval(3000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();

  if((Blynk.connected()) and (first)){
    Blynk.virtualWrite(V1, 1);
    Blynk.virtualWrite(V0, 1);

    first = false;
  }

}
