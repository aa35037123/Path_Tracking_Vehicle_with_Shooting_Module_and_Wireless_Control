bool mode = false;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(57600);
    Serial.println(mode);
    if(mode == true){
      mode = false;
    }
    else if (mode == false){
      mode = true;
    }
    Serial.println(mode);

}

void loop() {
  // put your main code here, to run repeatedly:

}
