byte data = B00000001;
byte shift = 0;
byte max = 8;
byte DDRD=B11111111;
byte PORTD = B00000000;
void setup() { // 將 Digital Pin 0-7 設定為

DDRD = B11111111;
}
void led_l(){
PORTD = B00000000; //關閉全部 LED
delay(100);
data=B00000001;
for(byte i=0; i<8; i++) {
PORTD = data;
delay(100);
data=data<<1; //左旋轉
}
}
void led_r(){
PORTD = B00000000;
delay(100);
data = B10000000;
for(byte i=0; i<8; i++){
PORTD = data;
delay(100);
data=data>>1; // 右旋轉
}
}
void loop() {
led_l();
led_r();
}
