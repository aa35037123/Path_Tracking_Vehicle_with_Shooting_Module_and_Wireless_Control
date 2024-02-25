#include <Servo.h>
Servo trigger;
Servo cannon;
//設定手把
int psdata = 8;
int pscmd = 9;
int psatt = 10;
int psclk = 11;
//設定馬達
//右輪馬達
int rightIn1 = 7;
int rightIn2 = 6;
int rightPWM = 3;
//左輪馬達
int leftIn1 = 13;
int leftIn2 = 12;
int leftPWM = 5;
//砲台馬達
int cannon_motor1 = 2;
int cannon_motor2 = A3;
int cannon_PWM = A4;
//砲台伺服馬達
//卡榫伺服馬達
//紅外線感測
const int L_IRsensor = A0;
const int C_IRsensor = 4;
const int R_IRsensor = A1;

int Ldigit, Cdigit, Rdigit;

void move_(int right_speed, int left_speed);
void IRsensor (int L,int C, int R);
void setup() {
  // put your setup code here, to run once:
    pinMode(rightIn1,OUTPUT);
    pinMode(rightIn2,OUTPUT);
    pinMode(rightPWM,OUTPUT);
    //左邊輪子馬達
    pinMode(leftIn1,OUTPUT);
    pinMode(leftIn2,OUTPUT);
    pinMode(leftPWM,OUTPUT);
    //感測器
    pinMode(L_IRsensor,INPUT);
    pinMode(C_IRsensor,INPUT);
    pinMode(R_IRsensor,INPUT);
    //砲台馬達
    pinMode(cannon_motor1,OUTPUT);
    pinMode(cannon_motor2,OUTPUT);
    pinMode(cannon_PWM,OUTPUT);
    digitalWrite(cannon_motor1, LOW);
    digitalWrite(cannon_motor2, HIGH);
    analogWrite(cannon_PWM,0);
    

    //卡榫設定
     trigger.attach(A2);  
     trigger.write(90);                              
     delay(1000); 
      
     //砲台伺服設定
     cannon.attach(A5);
     cannon.write(150);
     delay(1000);
     
     Serial.begin(57600);
     
     
    
}

void loop() {
  // put your main code here, to run repeatedly:
     Ldigit = digitalRead(L_IRsensor);
     Cdigit = digitalRead(C_IRsensor);
     Rdigit = digitalRead(R_IRsensor);
     if(Ldigit == 1)
        Serial.println("左邊黑色");
     else
        Serial.println("左邊白色");   
       
     if(Rdigit == 1)
        Serial.println("右邊黑色");
     else
        Serial.println("右邊白色");
    move_(0,0);     
    //IRsensor (Ldigit, Cdigit, Rdigit);
      
  
}
void move_(int right_speed, int left_speed)
{
  //若r_speed ＝ 0, 還是會向前轉，但速度是零
  // r_s = 255, l_s = 255：往前, r_s = -255, l_s = -255：往後
  // r_s = 255, l_s = -255：往左, r_s = -255, l_s = 255：往右
  if (right_speed >= 0)
  {
    digitalWrite(rightIn1, HIGH);
    digitalWrite(rightIn2, LOW);
  }
  else
  {
    digitalWrite(rightIn1, LOW);
    digitalWrite(rightIn2, HIGH);
  }
  
  if (left_speed >= 0)
  {
    digitalWrite(leftIn1, HIGH);
    digitalWrite(leftIn2, LOW);
  }
  else
  {
    digitalWrite(leftIn1, LOW);
    digitalWrite(leftIn2, HIGH);
  }
  // 控制速度的程式
  analogWrite(rightPWM, abs(right_speed));
  analogWrite(leftPWM, abs(left_speed));
  
}
void IRsensor (int L,int C,int R)  {
  
//1為黑，0為白 
  int counter = 0;
  //前進
  if ((L==0 and C==1 and R==0) or (L==1 and C==0 and R==1) or (L==0 and C==1 and R==1) or (L==1 and C==1 and R==0))
  {
      move_(200,200);
      delay(200);
      move_(0,0);
      delay(200);
      
          while(digitalRead(L_IRsensor)==0 and digitalRead(C_IRsensor)==0 and digitalRead(R_IRsensor)==0)
          {
            
             Serial.println("後退");
             move_(-150,-150);
             delay(200);
             move_(0,0);
             delay(200);
             //先右轉
             if(digitalRead(L_IRsensor)==0 and digitalRead(C_IRsensor)==0 and digitalRead(R_IRsensor)==0)
             {
                move_(-150, 150);
                delay(200);
                move_(0,0);
                delay(200);
             }
            
             //再左轉
             if(digitalRead(L_IRsensor)==0 and digitalRead(C_IRsensor)==0 and digitalRead(R_IRsensor)==0)
             {
                      move_(200,-200);
                      delay(200);
             }
          }
  }
  
          
      
  //右轉
  if(L==0 and C==0 and R==1)
  {
      move_(-100, 200);
      delay(200);
      move_(0,0);
      delay(200);
      //若超出範圍就左轉    
          while(digitalRead(L_IRsensor)==0 and digitalRead(C_IRsensor)==0 and digitalRead(R_IRsensor)==0)
          {

             move_(150,0);
             delay(200);
             move_(0,0);
             delay(200);
             counter++;
             if(counter>=2)
             {
                 move_(150,-150);
                 delay(200);
                 break;
                 
             }
          
          }
          
  }
      
  //左轉 
  if(L==1 and C==0 and R==0)
  {
      
      move_(200, -100);
      delay(200);
      move_(0,0);
      delay(200);
      //若超出範圍就右轉    
          while(digitalRead(L_IRsensor)==0 and digitalRead(C_IRsensor)==0 and digitalRead(R_IRsensor)==0)
          {
             move_(0,150);
             delay(200);
             move_(0,0);
             delay(200);
             counter++;
             if(counter>=2)
             {
                 move_(150,-150);
                 delay(200);
                 break;
                 
             }
          }
  }   
  //停止    
  if(L==1 and C==1 and R==1)
  {
    move_(0, 0);
    delay(200);
  }
  
  if(L==0 and C==0 and R==0)
  {
    move_(-150,-150);
    delay(200);
    move_(0,0);
    delay(200);  
  }
  
}     
