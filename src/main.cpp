#include <main.h>

#define DEBUG

WiFiClientSecure wClient;
PubSubClient mqttClient(wClient);

void setup() {
  // put your setup code here, to run once:
  WiFi.begin(ssid, password);
  Serial.print("Connecting WiFi");
  while(WiFi.status() != WL_CONNECTED){
    #ifdef DEBUG
    Serial.print(".");
    delay(500);
    #endif
  }
  Serial.println("Connected");

  wClient.setCACert(root_ca);
  if(hasClientCert){
    wClient.setCertificate(clientCert);
  }
  if(hasPrivateKey){
    wClient.setPrivateKey(privateKey);
  }

  Serial.print("Connecting MQTT Client...");
  if(mqttClient.connect(deviceID)){
    Serial.println("Connected");
  }else{
    Serial.println("Broker connection failed");
  }
  //Here you can set callbacks for MQTT subscriptions and also set topic to subscribe if needed.
  Serial.print("Running");


}

void loop() {
  //Recommend checking WiFi and MQTT Client connection on loop
  if(mqttClient.loop()){
    //Client is still connected, do things.
  }else{
    //Client disconnected so handle it.
  }
}
