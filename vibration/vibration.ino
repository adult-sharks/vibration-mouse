#define PIN_CNT 2

const int pin_num[2] = {3, 5};

void set_vibration_motor() {
  for (int i = 0; i < PIN_CNT; i++) {
    pinMode(pin_num[i], OUTPUT);
  }
}

void set_serial_communication() {
  Serial.begin(9600);
}

void execute_vibration_motor(int brightness) {
  int vibration;

  vibration = brightness * 2 > 255 ? 255 : brightness * 2;
  for (int i = 0; i < PIN_CNT; i++) {
    analogWrite(pin_num[i], vibration);
  }
}

void setup() {
  set_vibration_motor();
  set_serial_communication();
}

void loop() {
  static int brightness;

  if (Serial.available() > 0) {
    brightness = Serial.read();
    execute_vibration_motor(brightness);
  }
}