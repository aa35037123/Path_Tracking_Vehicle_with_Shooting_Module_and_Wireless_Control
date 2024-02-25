void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 10; i++)
  {
      delay(1000);
      Serial.println(i+1);
  } 
 
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
