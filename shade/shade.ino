int MotorForward = 7;
int MotorReverse = 6;


void setup() {
  Serial.begin(9600);
  pinMode(MotorForward,OUTPUT);
  pinMode(MotorReverse,OUTPUT);
}


void loop() {
 
  int a = 1;
  if(a==1){
    //forward // shade open
    digitalWrite(MotorForward,HIGH);
    digitalWrite(MotorReverse,LOW);
  }else if(a==2){
    //reverse // // shade close
    digitalWrite(MotorForward,LOW);
    digitalWrite(MotorReverse,HIGH);
  }else{
    //stop
    digitalWrite(MotorForward,LOW);
    digitalWrite(MotorReverse,LOW);
  }

}
