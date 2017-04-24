#define mic_pin A2 //定义声敏传感器引脚为A2
#define lightsensor_pin A0 //定义光敏传感器引脚为A0
#define PIN 8   //led灯控制引脚
#define PIN_NUM 2  //允许接的led灯的个数
#include <Adafruit_NeoPixel.h>  //调用LED彩灯的库文件


int state1; //定义一个整数变量state1
int state2; //定义一个整数变量state2
void setup() {
  Serial.begin(9600); //设置串口波特率为9600
  pinMode(mic_pin, INPUT); //设置声敏传感器引脚为输入状态
  pinMode(lightsensor_pin, INPUT); //设置光敏传感器引脚为输入状态

  Adafruit_NeoPixel ColorLED = Adafruit_NeoPixel(PIN_NUM, PIN, NEO_GRB + NEO_KHZ800);  //定义彩灯引脚以及数量
  ColorLED.begin(); //设置彩灯初始状态
}

void loop() {
  state1 = analogRead(mic_pin); //将声敏传感器引脚的值赋给变量state
  Serial.print("Sound:"); //在串口监视器里打印文字 Sound：
  Serial.println(state1); //在串口监视器里打印变量state的值，并换行

  state2 = analogRead(lightsensor_pin); //将光敏传感器引脚的值赋给变量state
  Serial.print("light:"); //在串口监视器里打印文字 state：
  Serial.println(state2); //在串口监视器里打印变量state的值，并换行

  if (state1 > 20 & state2 < 50) {  //如果光线较暗且有较大声音时，灯光做出反应
    ColorLED.setPixelColor(1, ColorLED.Color(0, 255, 0));  //设置彩灯颜色为红色
    ColorLED.setPixelColor(0, ColorLED.Color(0, 255, 0));  //设置彩灯颜色为红色
    ColorLED.show();  //显示彩灯效果
    delay(5000);  //保持1秒(1000毫秒)
  }
  else {  //如果不符合条件，灯光无反应
    ColorLED.setPixelColor(1, ColorLED.Color(0, 0, 0));  //关闭
    ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 0));  //关闭
    ColorLED.show();  //显示彩灯效果
  }
  delay(100); //延时100毫秒打印
}


