// #include <WiFi.h>
// #include <HTTPClient.h>

// // =============================
// // KONFIGURASI WIFI
// // =============================
// const char* ssid = "NAMA_WIFI_KAMU";
// const char* password = "PASSWORD_WIFI_KAMU";

// // =============================
// // KONFIGURASI SERVER
// // =============================
// const char* serverURL = "http://192.168.1.10:3000/api/sensor";
// // ⚠️ GANTI IP sesuai IP laptop kamu

// // =============================
// // KONFIGURASI SENSOR TDS
// // =============================
// #define TDS_PIN 34
// #define VREF 3.3       // tegangan ESP32
// #define ADC_RESOLUTION 4095.0

// void setup() {
//   Serial.begin(115200);

//   // =============================
//   // KONEK WIFI
//   // =============================
//   WiFi.begin(ssid, password);
//   Serial.print("Menghubungkan WiFi");

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("\nWiFi Terhubung!");
//   Serial.println(WiFi.localIP());
// }

// void loop() {
//   if (WiFi.status() == WL_CONNECTED) {

//     // =============================
//     // BACA SENSOR TDS
//     // =============================
//     int analogValue = analogRead(TDS_PIN);
//     float voltage = analogValue * (VREF / ADC_RESOLUTION);

//     // Rumus kasar TDS (ppm)
//     float tdsValue = (voltage * 1000) / 2;

//     Serial.print("TDS: ");
//     Serial.print(tdsValue);
//     Serial.println(" PPM");

//     // =============================
//     // KIRIM KE BACKEND
//     // =============================
//     HTTPClient http;
//     http.begin(serverURL);
//     http.addHeader("Content-Type", "application/json");

//     String jsonData = "{";
//     jsonData += "\"nutrisi\":";
//     jsonData += String(tdsValue, 0);
//     jsonData += "}";

//     int httpResponseCode = http.POST(jsonData);

//     if (httpResponseCode > 0) {
//       Serial.print("Response: ");
//       Serial.println(httpResponseCode);
//     } else {
//       Serial.print("Error: ");
//       Serial.println(httpResponseCode);
//     }

//     http.end();
//   }

//   // kirim tiap 5 detik
//   delay(5000);
// }
