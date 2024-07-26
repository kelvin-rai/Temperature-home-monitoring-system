//Temperature Monitoring System using Arduino and LM35
#include <SoftwareSerial.h>
int tempPin = A0;   // the output pin of LM35
int relay1 = 10;
int relay2 = 7;
int read_ADC= 0;
double temp = 0;
double tempC = 0;
double tempF = 0;

void setup() {
Serial.begin(9600); 
Serial.println("System Ready");
delay(1000);
pinMode(tempPin, INPUT);
pinMode(relay1, OUTPUT);
pinMode(relay2,OUTPUT);
}

void loop(){
read_ADC =0;

for (int i=0; i < 100; i++){   
read_ADC = read_ADC+ analogRead(tempPin);
delay(1); 
}
read_ADC = read_ADC/100; 
temp = (read_ADC / 1023.0) * 5000; // 5000 to get millivots.
tempC = temp * 0.1; // 500 is the offset
tempF = (tempC * 1.8) + 32; // conver to F  

if (tempC>=29)
{
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,LOW);
  Serial.print("   Temperature  ");
Serial.print(tempC,1);
Serial.print((char)223); //degree symbol 
Serial.print("C  ");

Serial.print(tempF,1);
Serial.print((char)223); //degree symbol 
Serial.print("F  ");

Serial.print("S");
Serial.print(";");
Serial.print(tempC,0); 
Serial.print(";");
Serial.print(tempF,0); 
Serial.println(";");   

delay(100);
}
else if(tempC>=25 && tempC <= 28)
{
  digitalWrite(relay1,LOW);
  digitalWrite(relay2,LOW);
  Serial.print("   Temperature  ");
  Serial.print(tempC,1);
Serial.print((char)223); //degree symbol 
Serial.print("C  ");

Serial.print(tempF,1);
Serial.print((char)223);
Serial.print("F  ");

Serial.print("S");
Serial.print(";");
Serial.print(tempC,0); 
Serial.print(";");
Serial.print(tempF,0); 
Serial.println(";");   

delay(100);
}
 else
 {
  digitalWrite(relay2,HIGH);
  digitalWrite(relay1,LOW);
  Serial.print("   Temperature  ");
Serial.print(tempC,1);
Serial.print((char)223); //degree symbol 
Serial.print("C  ");

Serial.print(tempF,1);
Serial.print((char)223); 
Serial.print("F  ");

Serial.print("S");
Serial.print(";");
Serial.print(tempC,0);
Serial.print(";");
Serial.print(tempF,0); 
Serial.println(";");   

delay(100);
 }
}
 

