int MotorForward = 7;
int MotorReverse = 6;


void setup() {
  Serial.begin(9600);
  pinMode(MotorForward,OUTPUT);
  pinMode(MotorReverse,OUTPUT);
}


void loop() {
 
  int a = 3;
  if(a==1){
    //forward // ehaust air out
    digitalWrite(MotorForward,HIGH);
    digitalWrite(MotorReverse,LOW);
  }else if(a==2){
    //reverse // air in
    digitalWrite(MotorForward,LOW);
    digitalWrite(MotorReverse,HIGH);
  }else{
    //stop
    digitalWrite(MotorForward,LOW);
    digitalWrite(MotorReverse,LOW);
  }

}
