byte data = B00000001;
byte shift = 0;
byte max = 8;
const byte sw=8;
void setup() { // 將 Digital Pin 0-7 設定為
pinMode(sw,INPUT);
DDRD = B11111111;
}
void led_0(){
  PORTD=B11111111;
  delay(1000);
 
}
void led_1(){
  PORTD=B00000000;
  delay(1000);
 
}
void led_l(){
PORTD = B00000000; //關閉全部 LED
delay(500);
data=B00000001;
for(byte i=0; i<8; i++) {
PORTD = data;
delay(500);
data=data<<1; //左旋轉
}
}
void led_r(){
PORTD = B00000000;
delay(500);
data = B10000000;
for(byte i=0; i<8; i++){
PORTD = data;
delay(500);
data=data>>1; // 右旋轉
}
}
void loop() {
  boolean val = digitalRead(8);
  if (val){
	led_l();
    led_r();}
  else {
    led_0();
    led_1();
  }
}
