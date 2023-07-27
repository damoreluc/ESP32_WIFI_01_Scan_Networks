# WiFi Esempio 01: scansione delle reti WiFi

Scansione delle reti WiFi circostanti, indicazione del loro SSID e del livello RSSI

Viene segnalato con un asterisco quali reti sono protette

__Nota__: nel file `soc.h` sono definiti i riferimenti ai due core della ESP32:
* `#define PRO_CPU_NUM (0)`

* `#define APP_CPU_NUM (1)`

Qui viene adoperata la `APP_CPU` per il codice utente, e la `PRO_CPU` per i protocolli di rete e la gestione del WiFi
