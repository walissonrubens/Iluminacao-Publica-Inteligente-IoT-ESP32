#define LDR_PIN    34
#define RELE_PIN   26
#define BUZZER_PIN 25
#define THRESHOLD  1500

void setup() {
  Serial.begin(115200);
  pinMode(RELE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(RELE_PIN, LOW);
  Serial.println("=== Sistema de Iluminacao IoT ===");
  Serial.println("[MQTT] Conectando ao broker HiveMQ...");
  Serial.println("[MQTT] Conectado! Topico: iot/iluminacao/luminosidade");
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);
  bool ligar = (ldrValue < THRESHOLD);

  digitalWrite(RELE_PIN, ligar ? HIGH : LOW);

  if (ligar) {
    tone(BUZZER_PIN, 1000, 200);
  }

  String status = ligar ? "LIGADO" : "DESLIGADO";
  String payload = "{\"ldr\":" + String(ldrValue)
                 + ",\"status\":\"" + status + "\"}";

  Serial.print("[MQTT] Publicando -> ");
  Serial.println(payload);
  Serial.print("[RELE] Estado: ");
  Serial.println(status);
  Serial.println("---");

  delay(2000);
}
