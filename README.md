# Iluminacao-Publica-Inteligente-IoT-ESP32

# Sistema de Iluminação Pública Inteligente baseado em IoT com ESP32

## Descrição

Este projeto apresenta um sistema de iluminação pública inteligente utilizando Internet das Coisas (IoT), desenvolvido com ESP32, sensor LDR e módulo relé.

O objetivo é automatizar o acionamento da iluminação conforme a luminosidade ambiente, reduzindo desperdícios de energia elétrica e contribuindo para o Objetivo de Desenvolvimento Sustentável 11 (ODS 11) – Cidades e Comunidades Sustentáveis.

Os dados coletados pelo sensor são enviados pela internet utilizando o protocolo MQTT através do broker público HiveMQ.

---

# Objetivos

* Automatizar o acionamento da iluminação pública.
* Reduzir o consumo desnecessário de energia.
* Demonstrar o uso do protocolo MQTT em aplicações IoT.
* Permitir monitoramento remoto dos dados coletados.

---

# Hardware Utilizado

## Plataforma de Desenvolvimento

* ESP32 DevKit V1

## Sensor

* LDR (Light Dependent Resistor)

## Atuadores

* Módulo Relé 5V
* Buzzer Ativo

## Outros Componentes

* Protoboard
* Resistores
* Jumpers
* Fonte USB 5V

---

# Arquitetura do Sistema

LDR → ESP32 → MQTT (HiveMQ) → Dashboard

O sensor LDR monitora a luminosidade ambiente.

O ESP32 processa os dados e toma decisões de acionamento.

Quando o ambiente está escuro:

* Relé é acionado
* Iluminação é ligada
* Status "LIGADO" é publicado via MQTT

Quando o ambiente está claro:

* Relé é desligado
* Iluminação é desligada
* Status "DESLIGADO" é publicado via MQTT

---

# Comunicação MQTT

## Broker

broker.hivemq.com

Porta:

1883

## Tópico MQTT

iot/iluminacao/luminosidade

## Exemplo de Mensagem

{
"ldr": 1320,
"status": "LIGADO"
}

---

# Fluxo de Funcionamento

1. ESP32 conecta ao Wi-Fi.
2. ESP32 conecta ao broker HiveMQ.
3. Sensor LDR realiza leitura da luminosidade.
4. Valor é comparado com o limiar configurado.
5. Se estiver escuro:

   * Relé liga
   * Buzzer emite sinal sonoro
6. Se estiver claro:

   * Relé desliga
   * Buzzer emite sinal sonoro
7. Dados são publicados via MQTT.
8. Dashboard recebe e exibe as informações.


# Instalação

1. Instalar Arduino IDE.
2. Instalar suporte para ESP32.
3. Instalar biblioteca WiFi.h.
4. Instalar biblioteca PubSubClient.
5. Configurar SSID e senha Wi-Fi.
6. Enviar o código para o ESP32.

---

# Software Desenvolvido

O firmware foi desenvolvido em linguagem C++ utilizando Arduino IDE.

Principais funções:

* Leitura analógica do sensor LDR.
* Controle automático do relé.
* Sinalização sonora com buzzer.
* Comunicação MQTT.
* Reconexão automática ao broker.

---

# Aplicação na ODS 11

Este projeto contribui para a ODS 11 (Cidades e Comunidades Sustentáveis) ao promover o uso eficiente da energia elétrica em sistemas de iluminação pública.

A automação reduz desperdícios energéticos, diminui custos operacionais e favorece a implementação de cidades inteligentes.

---

# Autor

Walisson Rubens Lopes de Oliveira

Curso: Análise e Desenvolvimento de Sistemas

Disciplina: Objetos Inteligentes Conectados

Universidade Presbiteriana Mackenzie
