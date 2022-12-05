#define PIN_NUM 3

void set_vibration_motor() {
  pinMode(PIN_NUM, OUTPUT);
}

void set_serial_communication() {
  Serial.begin(9600);
}

void execute_vibration_motor(int brightness) {
  int vibration;

  vibration = brightness * 2 > 255 ? 255 : brightness * 2;
  analogWrite(PIN_NUM, vibration);
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