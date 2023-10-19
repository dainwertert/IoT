#include <LiquidCrystal.h>

int seconds = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

int led1=13;//led Pin 13
int motor=10;//motor pin -10
int sensorValue;//Almacena el valor de llegada del sensor
float temp=0;// Almacena valor calculado de la temperatura

void setup()
{
  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
  pinMode(motor, OUTPUT);
  digitalWrite(motor, LOW);
  Serial.begin(9600);//Baudios
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
  lcd_1.print("Temperatura!");
}

void loop()
{
  sensorValue=analogRead(A0);//Es como un input
  temp = (sensorValue*(500.0/1024.0))-50.0; //LMP36
  lcd_1.setCursor(0, 1);
  Serial.println(temp);
  lcd_1.print(temp);
  lcd_1.println(" C° ");
  //lcd_1.println(" C° - ");
  //lcd_1.println(seconds);
  delay(1000); // Wait for 1000 millisecond(s)
  //seconds += 1;  
  if(temp <= 10.0){
    digitalWrite(motor, LOW);
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    delay(500);
  } else if(temp > 10.0 && temp < 26.0){
      digitalWrite(led1, LOW);
      digitalWrite(motor, LOW);
  } else if(temp >= 26.0){
      digitalWrite(led1, HIGH);
      digitalWrite(motor, HIGH);
  }  
}