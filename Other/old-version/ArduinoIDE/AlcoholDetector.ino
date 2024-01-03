#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino.h>
#include <ArduinoJson.h>

ESP8266WiFiMulti WiFiMulti;
WiFiClient client;
HTTPClient http;

#define ssid "HSU_Students"
#define password "dhhs12cnvch"
#define url "http://10.106.22.77:8080/person"
const char *SSID = ssid;
const char *PASSWORD = password;
const char *URL = url;

//settings
#define led D7
#define buzzer D6
#define sensorAnalog A0
#define air 680     //Input air value here
#define normal 700  //Input normal value here
#define drunk 800   //Input drunk value here
//json data
float p_StatusIndex;
String p_LName = "Input Here";
String p_MName = "Input Here";
String p_FName = "Input Here";

//============ Main Code ================
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setupComponents();
  setupWifi();
}
void loop() {
  // put your main code here, to run repeatedly:
  //testSensor();
  int sensorValue = analogRead(sensorAnalog);
  if (sensorValue > air) {
    if (sensorValue <= normal) {
      handleReadValue(sensorValue, "Normal!");
      handleComponentsOutput(1, 1);
      p_StatusIndex = sensorValue / 100;
      postJSONDataNormal();
    } else if (sensorValue > normal && sensorValue <= drunk) {
      handleReadValue(sensorValue, "Drinking but within legal limits!!");
      handleComponentsOutput(0, 1);
      p_StatusIndex = sensorValue / 100;
      postJSONDataDrinking();
    } else {
      handleReadValue(sensorValue, "DRUNK!!!");
      handleComponentsOutput(0, 0);
      p_StatusIndex = sensorValue / 100;
      postJSONDataDrunk();
    }
    delay(10000);
    refreshUntilReturnAir();
  } else {
    handleReadValue(sensorValue, "Air");
    delay(500);
  }
}

//====================================
void setupComponents() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  for (uint8_t t = 5; t > 0; t--) {
    Serial.printf("[SETUP SENSOR] WAIT %d...\n", t);
    Serial.flush();
    delay(5000);
  }
  Serial.println("SETUP COMPLETE!!!");
}
void setupWifi() {
  Serial.println("======= Connecting ========");
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(SSID, PASSWORD);
  while (WiFiMulti.run() != WL_CONNECTED) {
    delay(500);
    Serial.print("#");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("========== Set Up Complete ============== ");
}
//=====================================
void handleReadValue(int sensorValue, String status) {
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print("\t");
  Serial.print("Status: ");
  Serial.println(status);
}
//0: on; 1: off
void handleComponentsOutput(int ledMode, int buzzerMode) {
  if (ledMode == 1 && buzzerMode == 1) {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  } else if (ledMode == 0 && buzzerMode == 1) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
  } else if (ledMode == 0 && buzzerMode == 0) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
  }
}
void refreshUntilReturnAir() {
  int sensorValue = analogRead(sensorAnalog);
  int updateSensorValue;
  int airCheck = air - 0;
  int count = 0;
  handleComponentsOutput(1, 1);
  Serial.println("======================= REFRESH!!! ======================");
  while (true) {
    updateSensorValue = analogRead(sensorAnalog);
    if (updateSensorValue > airCheck) {
      Serial.printf("=== Loading...%d... ===\n", count++);
    } else {
      break;
    }
    delay(500);
  }
  Serial.println("================= REFRESH COMPLETE!!!!! =================");
  delay(2500);
  return;
}
//POST JSON Data
void postJSONDataNormal() {
  Serial.print("connecting to ");
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, URL)) {  // HTTP
      Serial.print("[HTTP] POST...\n");
      //gui du lieu len server dang JSON
      const int capacity = JSON_OBJECT_SIZE(6);
      StaticJsonDocument<capacity> doc;

      doc["p_LName"] = p_LName;
      doc["p_MName"] = p_MName;
      doc["p_FName"] = p_FName;
      doc["p_StatusIndex"] = p_StatusIndex;
      doc["p_Status"] = "Normal!";

      char output[2048];
      serializeJson(doc, Serial);
      serializeJson(doc, output);

      http.addHeader("Content-Type", "application/json");
      int httpCode = http.POST(output);
      Serial.println(httpCode);  //Print HTTP return code
      // file found at server
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String payload = http.getString();
        Serial.println(payload);
        Serial.println("done");
      } else {
        Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();  //Close connection Serial.println();
      Serial.println("closing connection");
    }
  }
}
void postJSONDataDrinking() {
  Serial.print("connecting to ");
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, URL)) {  // HTTP
      Serial.print("[HTTP] POST...\n");
      //gui du lieu len server dang JSON
      const int capacity = JSON_OBJECT_SIZE(6);
      StaticJsonDocument<capacity> doc;

      doc["p_LName"] = p_LName;
      doc["p_MName"] = p_MName;
      doc["p_FName"] = p_FName;
      doc["p_StatusIndex"] = p_StatusIndex;
      doc["p_Status"] = "Drinking but within legal limits!!";

      char output[2048];
      serializeJson(doc, Serial);
      serializeJson(doc, output);

      http.addHeader("Content-Type", "application/json");
      int httpCode = http.POST(output);
      Serial.println(httpCode);  //Print HTTP return code
      // file found at server
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String payload = http.getString();
        Serial.println(payload);
        Serial.println("done");
      } else {
        Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();  //Close connection Serial.println();
      Serial.println("closing connection");
    }
  }
}
void postJSONDataDrunk() {
  Serial.print("connecting to ");
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, URL)) {  // HTTP
      Serial.print("[HTTP] POST...\n");
      //gui du lieu len server dang JSON
      const int capacity = JSON_OBJECT_SIZE(6);
      StaticJsonDocument<capacity> doc;

      doc["p_LName"] = p_LName;
      doc["p_MName"] = p_MName;
      doc["p_FName"] = p_FName;
      doc["p_StatusIndex"] = p_StatusIndex;
      doc["p_Status"] = "DRUNK!!!";

      char output[2048];
      serializeJson(doc, Serial);
      serializeJson(doc, output);

      http.addHeader("Content-Type", "application/json");
      int httpCode = http.POST(output);
      Serial.println(httpCode);  //Print HTTP return code
      // file found at server
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String payload = http.getString();
        Serial.println(payload);
        Serial.println("done");
      } else {
        Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();  //Close connection Serial.println();
      Serial.println("closing connection");
    }
  }
}
void testSensor() {
  while(true) {
    int sensorValue = analogRead(sensorAnalog);
    Serial.print("Sensor value: "); Serial.println(sensorValue);
    delay(500);
  }
}