class motor
{
  public:
  int driver1Pin;
  int driver2Pin;
  int driver3Pin;
  int driver4Pin;

  void ubetterwork()
  {
    digitalWrite(driver1Pin, HIGH);  
    digitalWrite(driver2Pin, LOW);
    digitalWrite(driver3Pin, LOW);
    digitalWrite(driver4Pin, LOW);
    delay(50);
    digitalWrite(driver1Pin, LOW); 
  }

  void zzz()
  {
    digitalWrite(driver1Pin, LOW);
    digitalWrite(driver2Pin, LOW);
    digitalWrite(driver3Pin, LOW);
    digitalWrite(driver4Pin, LOW);
    delay(10);
  }

  void motor_init(int pin1, int pin2, int pin3, int pin4)
  {
    Serial.begin(9600);
  	driver1Pin = pin1;
    driver2Pin = pin2;
  	driver3Pin = pin3;
  	driver4Pin = pin4;
  	pinMode(driver1Pin, OUTPUT);
    pinMode(driver2Pin, OUTPUT);
  	pinMode(driver3Pin, OUTPUT);
  	pinMode(driver4Pin, OUTPUT);
  }
  
  void control(char char_data)    //controlling the motor
  {
  	Serial.print(char_data);
  	switch(char_data){
    case 'F':
    ubetterwork();
    break;
    case 'B':
    digitalWrite(driver1Pin, LOW);  
    digitalWrite(driver2Pin, HIGH);
    digitalWrite(driver3Pin, LOW);
    digitalWrite(driver4Pin, LOW);
    break;
    case 'L':
    digitalWrite(driver1Pin, LOW);  
    digitalWrite(driver2Pin, LOW);
    digitalWrite(driver3Pin, HIGH);
    digitalWrite(driver4Pin, LOW);
    break;
    case 'R':
    digitalWrite(driver1Pin, LOW);
    digitalWrite(driver2Pin, LOW);
    digitalWrite(driver3Pin, LOW);
    digitalWrite(driver4Pin, HIGH);
    break;
    case 'Z':
    zzz();
    break;
    default:
    break;
  }
  }
};
