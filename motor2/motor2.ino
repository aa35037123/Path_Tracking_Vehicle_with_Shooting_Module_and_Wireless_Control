
//上右下左
const int right_IN1 = 12;
const int right_IN2 = 11;
const int right_PWM = 13;
const int left_IN1 = 7;
const int left_IN2 = 6;
const int left_PWM = 5;


void move_(int right_speed, int left_speed);

void setup() {
  // put your setup code here, to run once:
    
    int right_speed = 255;
    int left_speed = 255;
    move_(right_speed, left_speed);
}

void loop() {
  // put your main code here, to run repeatedly:
    
}

void move_(int right_speed, int left_speed)
{
  //若r_speed ＝ 0, 還是會向前轉，但速度是零
  // r_s = 255, l_s = 255：往前, r_s = -255, l_s = -255：往後
  // r_s = 255, l_s = -255：往左, r_s = -255, l_s = 255：往右
  if (right_speed >= 0)
  {
    digitalWrite(right_IN1, HIGH);
    digitalWrite(right_IN2, LOW);
  }
  else
  {
    digitalWrite(right_IN1, LOW);
    digitalWrite(right_IN2, HIGH);
  }
  
  if (left_speed >= 0)
  {
    digitalWrite(left_IN1, HIGH);
    digitalWrite(left_IN2, LOW);
  }
  else
  {
    digitalWrite(left_IN1, LOW);
    digitalWrite(left_IN2, HIGH);
  }
  // 控制速度的程式
  analogWrite(right_PWM, abs(left_speed));
  analogWrite(left_PWM, abs(left_speed));
  
}
