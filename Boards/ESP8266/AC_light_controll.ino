/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

String  ClientRequest;
WiFiServer server(80);

void setup()
{
  ClientRequest = "";

  pinMode(14, OUTPUT);
  Serial.begin(9600);
  
  server.begin();
  
  WiFi.disconnect();
  digitalWrite(14,HIGH);
  delay(3000);
  Serial.println("START");
   WiFi.begin("Rajawat","jacksparrow");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("...");

  }
  Serial.println("Connected");
  Serial.println("Your ip is");
  Serial.println((WiFi.localIP().toString()));

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    ClientRequest = (client.readStringUntil('\r'));
    Serial.println(ClientRequest);
    if (ClientRequest.equals("0")) {
      digitalWrite(14,HIGH);

    }
    if (ClientRequest.equals("1")) {
      digitalWrite(14,LOW);

    }

}
