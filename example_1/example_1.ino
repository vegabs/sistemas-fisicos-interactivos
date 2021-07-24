/*
 * EJERCICIO 1: Mensaje serial 
 */

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Hello from ESP32!\n");
  delay(500);
}
