void setup() 
{
Serial.begin(9600);
int ldr=A0;
int led=3;
int flame=6;
int buzzer=7;
pinMode(flame,INPUT);
pinMode(buzzer,OUTPUT);
pinMode(3,OUTPUT);
pinMode(A0,INPUT);
}

void loop() 
{
//C# interface
String s=Serial.readString();
if(s=="on")
{
    digitalWrite(3,HIGH);

}
else if(s=="off")
{
    digitalWrite(3,LOW);
}

//fire alarm system
int Flame=digitalRead(6);
if(Flame==LOW)
{
  digitalWrite(7,HIGH);
  delay(1000);
}
else if(Flame==HIGH)
{
  digitalWrite(7,LOW);
  delay(1000);
}

//automatic lighting
int r=analogRead(A0);
Serial.println(r);
delay(500);
if(r<80)
{
  digitalWrite(3,LOW);
}
if(r>80)
{
  digitalWrite(3,HIGH);
}

}
