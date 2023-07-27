/*
 * WiFi Esempio 01: scansione delle reti WiFi
 * 
 * Nota: nel file soc.h sono definiti i riferimenti ai due core della ESP32:
 *   #define PRO_CPU_NUM (0)
 *   #define APP_CPU_NUM (1)
 * 
 * Qui viene adoperata la APP_CPU
 * 
*/

#include <Arduino.h>
#include <WiFi.h>


void setup() {
  Serial.begin(115200);
  Serial.println("WiFi Esempio 01: scansione delle reti WiFi");

  // Imposta il modulo WiFi in modalità "station" 
  // e si disconnette dall'access point al quale era connesso in precedenza
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup terminato");
}

void loop() {
  Serial.println("Inizio scansione");

  // WiFi.scanNetworks restituisce il numero di reti WiFi scoperte
  int n = WiFi.scanNetworks();

  // visualizzazione dei risultati
  Serial.println("scansione eseguita");
  if (n == 0) {
      Serial.println("non sono state trovate reti WiFi");
  } else {
    Serial.print("sono state trovate ");
    Serial.print(n);
    Serial.println(" reti WiFi");

    // stampa i dettagli delle reti trovate:
    for (int i = 0; i < n; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
      delay(10);
    }
  }
  Serial.println("");

  // Pausa e poi ricomincia la scansione
  delay(5000);
}