//motor control

const int In1 = 4;
const int In2 = 5;
const int In3 = 6;
const int In4 = 7;

void setup(){
pinMode(In1, OUTPUT);
pinMode(In2, OUTPUT);
pinMode(In3, OUTPUT);
pinMode(In4, OUTPUT);
}

void movefront(){
digitalWrite(In1, HIGH);
digitalWrite(In2, LOW);
digitalWrite(In3, HIGH);
digitalWrite(In4, LOW);
}

void moveback(){
digitalWrite(In1, LOW);
digitalWrite(In2, HIGH);
digitalWrite(In3, LOW);
digitalWrite(In4, HIGH);
}

void movestop(){
digitalWrite(In1, LOW);
digitalWrite(In2, LOW);
digitalWrite(In3, LOW);
digitalWrite(In4, LOW);
}

void moveright(){
digitalWrite(In1, HIGH);
digitalWrite(In2, LOW);
digitalWrite(In3, LOW);
digitalWrite(In4, HIGH);
}

void moveleft(){
digitalWrite(In1, LOW);
digitalWrite(In2, HIGH);
digitalWrite(In3, HIGH);
digitalWrite(In4, LOW);
}

void loop(){
movefront();
delay(2000);
moveback();
delay(2000);
movestop();
delay(2000);
}
