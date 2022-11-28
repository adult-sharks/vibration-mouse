var SerialPort = require("serialport").SerialPort;
// 포트: Arduino Uno(COM11)
// baudRate: 9600
// SerialPort 객체 생성
var serialPort = new SerialPort({
  path:"COM11",
  baudRate:9600, 
}, false);
var brightness = 0; // sandbox.js 으로부터 받아올 값

serialPort.open(() => {
  console.log("connected...");
  // Arduino 로부터 data 전송을 받아옴
  serialPort.on("data", (data) => {
    console.log("data received: " + data);
  });
  // 50 ms 단위로 brightness 값을 Arduino 에 전송함
  setInterval(() => {
    brightness = (brightness + 1) % 128;
    var charBrightness = String.fromCharCode(brightness);
    serialPort.write(charBrightness, (err, results) => {});
  }, 50);
});