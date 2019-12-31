#include <Adafruit_NeoPixel.h>   // 네오픽셀 라이브러리를 불러옵니다.

#define PIN 5                      // 디지털핀 어디에 연결했는지 입력
#define LEDNUM 24                  // 연결된 네오픽셀의 숫자입력
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDNUM, PIN, NEO_GRB + NEO_KHZ800);
int val = 0;
int val_1= 0;
int a=0;

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3); // RX, TX
void setup() {

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");
  
  mySerial.begin(9600);
 // mySerial.println("Hello, world?");
}

void loop() {                              // 이 안에 입력한 내용들이 반복 실행됩니다
  strip.begin();                           // 네오픽셀 제어시작
  strip.show();  // 네오픽셀 초기화
//   strip.setPixelColor(19, 255, 0, 0); // (A,R,G,B) A번째 LED를 RGB (0~255) 만큼의 밝기로 켭니다.
 


 if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
  val = analogRead(A0);
  val_1=map(val,0,1023,0,255);
 // Serial.println(val_1);
  analogWrite(5,val_1);
  delay(100);
/*
 if (val_1 < 60){
for(int i=0; i < 24; i++){
    strip.setPixelColor(i, 100, 255, 255);  
 }

  }
else {
for(int i=0; i < 24; i++){
  strip.setPixelColor(i, 1, 255, 1); 
}
}
*/
if (mySerial.available() > 0) {
  a = mySerial.read();
  Serial.print(a);
  switch (a) {
    case 0:
    for(int i=0; i < 24; i++){
  strip.setPixelColor(i, 0, 0, 0);  //무
} break;

  case 1: for(int i=0; i < 24; i++){
    strip.setPixelColor(i, 0, 0, 255);  //파
  }break;
  
  case 2: for(int i=0; i < 24; i++){
    strip.setPixelColor(i, 0, 255, 0);  //초
  }break;
  
  case 3: for(int i=0; i < 24; i++){
   strip.setPixelColor(i, 50, 255, 1);  //노
  }break;
  
    case 4: for(int i=0; i < 24; i++){
    strip.setPixelColor(i, 100, 255, 1);  //주
    }break;
    
      case 5: for(int i=0; i < 24; i++){
    strip.setPixelColor(i, 255, 0, 0);   //빨
 
      }break;

  
}
}
}
