void setup() {
  Serial.begin(115200);
}

void loop() {

  byte myBuffer[9];

  if (Serial.available() >= 9) {

    // prueba
    // d5 55 60 45 2b d5 55 60 45
    Serial.readBytes(myBuffer, 9);

    byte bufferFloat1[4] = {myBuffer[0], myBuffer[1], myBuffer[2], myBuffer[3]};
    float float1 = *(float *)&bufferFloat1;

    byte bufferFloat2[4] = {myBuffer[5], myBuffer[6], myBuffer[7], myBuffer[8]};
    float float2 = *(float *)&bufferFloat2;

    float respuesta = 0.0;

    switch (myBuffer[4]) {
      case 0x2B:
        respuesta = float1 + float2;
        break;
      case 0x2D:
        respuesta = float1 - float2;
        break;
      case 0x2A:
        respuesta = float1 * float2;
        break;
      case 0x2F:
        respuesta = float1 / float2;
        break;
      default:
        respuesta = 6.0;
        break;
    }

    uint8_t arr[4] = {0};
    memcpy(arr, (uint8_t *)&respuesta, 4);
    // Serial.write(myBuffer, 9);
    Serial.write(arr, 4);
  }

  memset(myBuffer, 0, sizeof(myBuffer));
}
