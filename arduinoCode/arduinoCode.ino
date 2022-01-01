//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>
//#include <DHT.h>    // Install DHT11 Library and Adafruit Unified Sensor Library



// apiKey: "AIzaSyBB29Bzt39YAZpaNhvXTJywGIzw7_fWaeg",
//  authDomain: "stage-cleaner.firebaseapp.com",
#define FIREBASE_HOST "stage-cleaner-default-rtdb.firebaseio.com" //Without http:// or https:// schemes
#define FIREBASE_AUTH "xdBy3YYyyL509HLeqT9tWbifppDsLRaN1eUW0Ki4"
#define WIFI_SSID "Mukund_Speed"
#define WIFI_PASSWORD "Five@Mitsoe"

//#define DHTPIN 2    // Connect Data pin of DHT to D2
//int led = D5;     // Connect LED to D5

//#define DHTTYPE    DHT11
//DHT dht(DHTPIN, DHTTYPE);

//Define FirebaseESP8266 data object
FirebaseData firebaseData;
FirebaseData ledData;

FirebaseJson json;


void setup()
{

  Serial.begin(9600);

//  dht.begin();
//  pinMode(led,OUTPUT);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}

//void sensorUpdate(){
//  // Reading temperature or humidity takes about 250 milliseconds!
//  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
////  float h = dht.readHumidity();
//  // Read temperature as Celsius (the default)
////  float t = dht.readTemperature();
//  // Read temperature as Fahrenheit (isFahrenheit = true)
////  float f = dht.readTemperature(true);
//
//  // Check if any reads failed and exit early (to try again).
//  if (isnan(h) || isnan(t) || isnan(f)) {
//    Serial.println(F("Failed to read from DHT sensor!"));
//    return;
//  }
//
//  Serial.print(F("Humidity: "));
//  Serial.print(h);
//  Serial.print(F("%  Temperature: "));
//  Serial.print(t);
//  Serial.print(F("C  ,"));
//  Serial.print(f);
//  Serial.println(F("F  "));
//
//  if (Firebase.setFloat(firebaseData, "/FirebaseIOT/temperature", t))
//  {
//    Serial.println("PASSED");
//    Serial.println("PATH: " + firebaseData.dataPath());
//    Serial.println("TYPE: " + firebaseData.dataType());
//    Serial.println("ETag: " + firebaseData.ETag());
//    Serial.println("------------------------------------");
//    Serial.println();
//  }
//  else
//  {
//    Serial.println("FAILED");
//    Serial.println("REASON: " + firebaseData.errorReason());
//    Serial.println("------------------------------------");
//    Serial.println();
//  }
//
//  if (Firebase.setFloat(firebaseData, "/FirebaseIOT/humidity", h))
//  {
//    Serial.println("PASSED");
//    Serial.println("PATH: " + firebaseData.dataPath());
//    Serial.println("TYPE: " + firebaseData.dataType());
//    Serial.println("ETag: " + firebaseData.ETag());
//    Serial.println("------------------------------------");
//    Serial.println();
//  }
//  else
//  {
//    Serial.println("FAILED");
//    Serial.println("REASON: " + firebaseData.errorReason());
//    Serial.println("------------------------------------");
//    Serial.println();
//  }
//}
void loop() {
//  sensorUpdate();
  
  if (Firebase.getString(ledData, "/x/cmd")){
    Serial.println(ledData.stringData());
    if (ledData.stringData() == "left") {
//    digitalWrite(led, HIGH);
      Serial.println("LEFT");
    }
  else if (ledData.stringData() == "right"){
//    digitalWrite(led, LOW);
      Serial.println("RIGHT");
    }
  else if (ledData.stringData() == "forward"){
//    digitalWrite(led, LOW);
      Serial.println("FORWARD");
    }
  else if (ledData.stringData() == "backward"){
//    digitalWrite(led, LOW);
      Serial.println("BACKWARD");
    }
  }
  delay(100);
}