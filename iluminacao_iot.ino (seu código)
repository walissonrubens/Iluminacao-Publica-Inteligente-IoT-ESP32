#include <WiFi.h>
#include <PubSubClient.h>

#define LDR_PIN    34
#define RELE_PIN   26
#define BUZZER_PIN 25
#define THRESHOLD  1500

// WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// MQTT
const char* mqtt_server = "broker.hivemq.com";
const char* mqtt_topic  = "iot/iluminacao/luminosidade";

WiFiClient espClient;
PubSubClient client(espClient);

bool ultimoEstado = false;

void conectarWiFi() {
  Serial.print("Conectando ao WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void conectarMQTT() {
  while (!client.connected()) {

    Serial.print("Conectando ao HiveMQ... ");

    String clientId = "ESP32-" + String(random(1000, 9999));

    if (client.connect(clientId.c_str())) {
      Serial.println("OK");
    } else {
      Serial.print("Falhou. rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente...");
      delay(2000);
    }
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(RELE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(RELE_PIN, LOW);

  conectarWiFi();

  client.setServer(mqtt_server, 1883);

  Serial.println("=== Sistema de Iluminacao IoT ===");
}

void loop() {

  if (!client.connected()) {
    conectarMQTT();
  }

  client.loop();

  int ldrValue = analogRead(LDR_PIN);

  bool ligar = (ldrValue < THRESHOLD);

  digitalWrite(RELE_PIN, ligar ? HIGH : LOW);

  if (ligar != ultimoEstado) {
    tone(BUZZER_PIN, 1000, 200);
    ultimoEstado = ligar;
  }

  String status = ligar ? "LIGADO" : "DESLIGADO";

  String payload =
    "{\"ldr\":" + String(ldrValue) +
    ",\"status\":\"" + status + "\"}";

  client.publish(mqtt_topic, payload.c_str());

  Serial.println("================================");
  Serial.print("LDR: ");
  Serial.println(ldrValue);

  Serial.print("Estado do rele: ");
  Serial.println(status);

  Serial.print("MQTT -> ");
  Serial.println(payload);

  Serial.println("================================");

  delay(5000);
}
