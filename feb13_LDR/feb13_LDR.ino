int data_pin=3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  int data=digitalRead(data_pin);
 
  Serial.print(data);
  Serial.print('\n');
  delay(100);
}
