#define ALIVELED 18
#define DIGITAL_OUT 5
#define DIGITAL_IN 19
#define ANALOG_IN 34

void setup() {
  pinMode(ALIVELED, OUTPUT);
  digitalWrite(DIGITAL_OUT, true);
  pinMode(DIGITAL_OUT, OUTPUT);
  pinMode(DIGITAL_IN, INPUT_PULLUP); // le agrega una resistencia
  Serial.begin(115200);
}

void task1() {
  static uint32_t oldTime = 0;
  static bool ledState = false;
  const uint32_t interval = 500;

  uint32_t newTime = millis();

  if ((newTime - oldTime) >= interval) {
    oldTime = newTime;
    if (ledState == false) {
      ledState = true;
    }
    else ledState = false;
    digitalWrite(ALIVELED, ledState);
  }
}

void task2() {
  static bool digitalOutState = false;

  if (Serial.available() > 0) {
    String dato = Serial.readStringUntil('\n');

    if (dato == "read") {
      Serial.print(digitalRead(DIGITAL_IN));
      Serial.print(',');
      Serial.print(analogRead(ANALOG_IN));
      Serial.print(',');
      Serial.print(digitalOutState);
      Serial.print('\n');

    } else if (dato == "outON") {

      digitalOutState = true;
      digitalWrite(DIGITAL_OUT, !digitalOutState);
      Serial.print(digitalOutState);
      Serial.print('\n');

    } else if (dato == "outOFF") {

      digitalOutState = false;
      digitalWrite(DIGITAL_OUT, !digitalOutState);
      Serial.print(digitalOutState);
      Serial.print('\n');
    }
  }
}

void loop() {
  task1();
  task2();
}
