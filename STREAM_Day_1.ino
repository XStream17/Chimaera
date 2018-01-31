// Variable to store received character
char char_data = 0;

// Digital pin number for motor driver
int driver1Pin = 5;
int driver2Pin = 6;
int driver3Pin = 9;
int driver4Pin = 10;


void setup()
{
  // put your setup code here, to run once:

  // for motor driver L293D
  pinMode(driver1Pin, OUTPUT);
  pinMode(driver2Pin, OUTPUT);
  pinMode(driver3Pin, OUTPUT);
  pinMode(driver4Pin, OUTPUT);

  // for Bluetooth
  Serial.begin(9600);
}


void loop()
{
  // put your main code here, to run repeatedly:

  // if something is received
  if (Serial.available() > 0)
  {
    // read and store it in char_data
    char_data = Serial.read();
  }

  // if char_data == ...?
  switch(char_data)
  {
    // Forward
    case 'F':
    digitalWrite(driver1Pin, HIGH); 
    digitalWrite(driver2Pin, LOW);
    digitalWrite(driver3Pin, HIGH);
    digitalWrite(driver4Pin, LOW);
    delay(50);
    break;

    // Backward
    case 'B':
    digitalWrite(driver1Pin, LOW);  
    digitalWrite(driver2Pin, HIGH);
    digitalWrite(driver3Pin, LOW);
    digitalWrite(driver4Pin, HIGH);
    delay(50);
    break;

    // Left
    case 'L':
    digitalWrite(driver1Pin, HIGH);  
    digitalWrite(driver2Pin, LOW);
    digitalWrite(driver3Pin, LOW);
    digitalWrite(driver4Pin, HIGH);
    delay(50); 
    break;

    // Right
    case 'R':                     
    digitalWrite(driver1Pin, LOW);  
    digitalWrite(driver2Pin, HIGH);
    digitalWrite(driver3Pin, HIGH);
    digitalWrite(driver4Pin, LOW);
    delay(50); 
    break;

    // Stop
    case 'Z':
    digitalWrite(driver1Pin, LOW);
    digitalWrite(driver2Pin, LOW);
    digitalWrite(driver3Pin, LOW);
    digitalWrite(driver4Pin, LOW);
    delay(50);
    break;   
  }
}
