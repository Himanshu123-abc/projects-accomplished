 #include <SoftwareSerial.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

//LiquidCrystal_I2C lcd(Declare a LiquidCrystal_I2C object with I2C address, the number of columns, the number of rows
SoftwareSerial mySerial(8, 7);

int flamePin= 11;
int gasA0 = A0;
int redled= 13;
int greenled= 4;
int buzzer = 9;
int sensorThres = 100;


int analogSensor;
int Flame = LOW; 
int sensor_Status;
int sms_count=0;

void setup()
{
//defining pinmode
pinMode(flamePin,INPUT);
pinMode(gasA0,INPUT);
pinMode(redled,OUTPUT);
pinMode(greenled, OUTPUT);
pinMode(buzzer, OUTPUT);
Serial.begin(9600);   
mySerial.begin(9600);
lcd.init(); 
lcd.backlight(); 
delay(1000);
}

void loop()
{
  Check_Sensor();
  CheckShutDown();
}

void Check_Sensor()       ///function for checking ststus of sensor
{
  Flame = digitalRead(flamePin);
  Serial.print("Flame status: ");
  Serial.println(Flame);
  analogSensor = analogRead(gasA0);
  Serial.print("Gas value: ");
  Serial.println(analogSensor);
  Serial.println("-------------------------------------");
  delay(1000);
  lcd.print("Status:");
  
//conditions for sending alert
  if (Flame== HIGH  && analogSensor > sensorThres)
  {
    
    Serial.println("Fire and gas detected");
    Serial.println("********************************");
    alert1();
  }
  else if (Flame== HIGH)
  {
    Serial.println("Fire detected");
    Serial.println("********************************");
    alert2();
  }
  else if (analogSensor > sensorThres)
  {
    Serial.println("Gas detected");
    Serial.println("********************************");
    alert3();
  }
  else
  {
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH);
    noTone(buzzer);
    Serial.println("no worries...");
    Serial.println("*********************************");
    lcd.setCursor(0, 1);
    lcd.print("NO Worries");
    
   
  }
  delay(1000);
  lcd.clear();
}
//--------------------------------------------------------------------------------------------------------------


void alert1() 
{
  digitalWrite(redled, HIGH);
  delay(1000);
  digitalWrite(greenled, LOW);
  digitalWrite(buzzer, HIGH);
  Serial.print("Alert!Buzzer on");
  //tone(buzzer,5000,100);
  //delay(500);
  lcd.setCursor(0,1);
  lcd.print("FIRE and Gas Alert");
  while(sms_count<1) //Number of SMS Alerts to be sent
  {
    SendTextMessage1(); // Function to send AT Commands to GSM module
  }
  sensor_Status=1;
    
}
//----------------------------------------------------------------------------------------------------------------
void alert2()
{
  digitalWrite(redled, HIGH);
  delay(1000);
  digitalWrite(greenled, LOW);
  digitalWrite(buzzer, HIGH);
  
  //tone(buzzer,5000,100);
  //delay(500);
  lcd.setCursor(0,1);
  lcd.print("#FIREEEE Alert#");
  while(sms_count<1) //Number of SMS Alerts to be sent
  {
    SendTextMessage2(); // Function to send AT Commands to GSM module
  }
  sensor_Status=1;
    
}
//------------------------------------------------------------------------------------------------------------------
void alert3()
{
  digitalWrite(redled, HIGH);
  delay(1000);
  digitalWrite(greenled, LOW);
  digitalWrite(buzzer, HIGH);
  Serial.print("Alert!Buzzer on");
  Serial.println(" ");
  //tone(buzzer,5000,100);
  //delay(500);
  lcd.setCursor(0,1);
  
  lcd.print("Gas Alert#");
  while(sms_count<1) //Number of SMS Alerts to be sent
  {
    SendTextMessage3(); // Function to send AT Commands to GSM module
  }
  sensor_Status=1;
    
}
//----------------------------------------------------------------------------------------------

void CheckShutDown()
{
if(sensor_Status==1)
{
  analogSensor = analogRead(gasA0);
  if (Flame== LOW && analogSensor < sensorThres)
  {
    //lcd.setCursor(0,1);
    //lcd.print("No Gas Leaking");
    noTone(buzzer);
    delay(1000);
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH);
    sms_count=0;
    sensor_Status=0;
  

}}}
//-------------------------------------------------------------------------------------------------------

void SendTextMessage1()
{
  Serial.println("Initializing..."); 
  delay(500);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"+9779867817325\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print("FIre and gas Alert"); //text content
  updateSerial();
  mySerial.write(26);//the message stopping character
  sms_count++;
  delay(500);
  
}
//--------------------------------------------------------------------------
void SendTextMessage2()
{
  Serial.println("Initializing..."); 
  delay(500);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"+9779867817325\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print("FIre Alert"); //text content
  updateSerial();
  mySerial.write(26);//the message stopping character
  sms_count++;
  delay(500);
  
}
//-----------------------------------------------------------------------------------------------
void SendTextMessage3()
{
  Serial.println("Initializing..."); 
  delay(500);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"+9779867817325\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print("Gas Alert"); //text content
  updateSerial();
  mySerial.write(26);//the message stopping character
  sms_count++;
  delay(500);
  
}
//--------------------------------------------------------------------------------------------------

void updateSerial()
{
  delay(500);
  while(Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
  delay(500);
}
//--------------------------------------------------------------------------------------------------
