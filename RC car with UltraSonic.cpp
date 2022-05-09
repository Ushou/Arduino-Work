#define Motor_Right_Speed 5 //Motor Right pin

#define Motor_Right_Dir 2

#define Motor_Left_Speed 4  //Motor Left pin;

#define Motor_Left_Dir 1

const int TrigPin = D5;  //UltraSonic Triger pin

const int EchoPin = D8;  //UltraSoni Echo pin

long duration, cm ; 

void setup() {

  Serial.begin (9600);

  pinMode(TrigPin,OUTPUT);

  pinMode(EchoPin,INPUT);

  pinMode(Motor_Right_Speed,OUTPUT);

  pinMode(Motor_Right_Dir,OUTPUT);

  pinMode(Motor_Left_Speed,OUTPUT);

  pinMode(Motor_Left_Dir,OUTPUT);

}

void loop() {

  digitalWrite(Motor_Right_Speed,LOW);

  digitalWrite(Motor_Right_Dir,LOW);

  digitalWrite(Motor_Left_Speed,LOW);

  digitalWrite(Motor_Left_Dir,LOW);

  get_distance();

  if(cm>30){                

  digitalWrite(Motor_Right_Speed,HIGH); //go forward

  digitalWrite(Motor_Right_Dir,LOW);

  digitalWrite(Motor_Left_Speed,HIGH);

  digitalWrite(Motor_Left_Dir,LOW);

  delay(250);

  }

  if (cm<=30){
    digitalWrite(Motor_Right_Speed,LOW);   //stop

    digitalWrite(Motor_Right_Dir,LOW);

    digitalWrite(Motor_Left_Speed,LOW);

    digitalWrite(Motor_Left_Dir,LOW);
    delay(500);
    
    digitalWrite(Motor_Right_Speed,HIGH); //turn left

    digitalWrite(Motor_Right_Dir,LOW);

    digitalWrite(Motor_Left_Speed,LOW);

    digitalWrite(Motor_Left_Dir,LOW);

    delay(500);

  }

}

void get_distance(){

  digitalWrite(TrigPin, LOW);

  delay(5);

  digitalWrite(TrigPin, HIGH);

  delay(10);

  digitalWrite(TrigPin, LOW);

  pinMode(EchoPin, INPUT);

  duration = pulseIn(EchoPin, HIGH);

  cm = (duration/2) / 29.1;  

  Serial.print("Distance:");

  Serial.print(cm);     //印出距離值 cm 在序列埠監控顯示器 單位公分

  Serial.println(" cm");

  delay(10); 

}

