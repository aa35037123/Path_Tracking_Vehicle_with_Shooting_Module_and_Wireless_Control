int digital1 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(digital1, INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  float val = digitalRead(digital1);
  if(val == 1)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
    

}
