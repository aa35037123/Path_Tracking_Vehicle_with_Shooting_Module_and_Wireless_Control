#include <Servo.h>

Servo myservo;  //宣告伺服馬達物件

void setup() {
  myservo.attach(A2); //伺服馬達信號線腳位
  myservo.write(100);  //轉動角度(0~180度)                                  
  delay(3000); 
}

void loop() {
  
                           
}
