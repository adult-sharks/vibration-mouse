#define PIN_CNT 3

int pin_num[3] = {3, 5, 6};

/*
 * 3, 5, 6번 핀에 대응하는 진동 모터 세팅
 */
void set_vibration_motor() {
  for (int i = 0; i < PIN_CNT; i++) {
    pinMode(pin_num[i], OUTPUT);
  }
}

/*
 * 시리얼 통신 세팅
 */
void set_serial_communication() {
  Serial.begin(9600);
}

/*
 * brightness : 밝기값
 * 밝기값을 진동값으로 변경 후 진동 모터에 적용
 */
void execute_vibration_motor(int brightness) {
  int vibration;

  vibration = brightness * 2 > 255 ? 255 : brightness * 2;
  for (int i = 0; i < PIN_CNT; i++) {
    analogWrite(pin_num[i], brightness);
  }
}

void setup(){
  set_vibration_motor();
  set_serial_communication();
}

void loop(){
  static int brightness;

  // brightness 값을 sandbox.js 으로부터 받아온 경우
  if (Serial.available() > 0) {
    brightness = Serial.read();
    execute_vibration_motor(brightness);
  }
}