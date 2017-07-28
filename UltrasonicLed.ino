unsigned char echo = 8;
unsigned char trig = 7;
unsigned long ultrasoundValue = 0.00;
float showCM ;
float showIN ;
int led = 3;


void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.print("?f");
  pinMode(led,OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  ultrasoundValue = pulseIn(echo,HIGH);
  showCM = ultrasoundValue*0.017;
  showIN = showCM/2.54;
  

  Serial.println(ultrasoundValue);
  
  Serial.println(showCM);

  delay(250);

  if(showCM <= 5)
    digitalWrite(led,HIGH);
  if(showCM > 5)
    digitalWrite(led,LOW);
}

