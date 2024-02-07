
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int sensor=A0;
float sensor_read;
float temp;
void setup()
{
Serial.begin(9600);
lcd.begin(16, 2);
}

void loop() 
{
  
//C# interface  
String s=Serial.readString();
if(s!="clear")
{
  lcd.print(s);
}
else
{
  lcd.clear();
}

//Displaying temperature
sensor_read=analogRead(sensor);
temp=(sensor_read*5*100)/1024;
lcd.setCursor(0,0);
lcd.print(temp);
delay(500);
lcd.clear();
}
