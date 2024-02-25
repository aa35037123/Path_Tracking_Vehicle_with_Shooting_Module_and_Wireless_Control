void setup() {
  // put your setup code here, to run once:
  // 第8角位是輸出
     pinmode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //控制訊號大小，８: 輸出位置, HIGH: 1, LOW: 0, delay: 延遲以毫秒記
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(8, LOW);
    delay(1000);
}
