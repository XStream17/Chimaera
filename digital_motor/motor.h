class motor_digital
{
  const int motor1Pin;
  const int motor2Pin;
  const int driver1Pin;
  const int driver2Pin;
  int mstate1;
  int mstate2;
  int dir1;
  int dir2;
  

  public:
  motor(int pin1, int pin2, int dpin1, int dpin2)
  {
    Serial.begin(9600);
	motor1Pin = pin1;
    motor2Pin = pin2;
	driver1Pin = dpin1;
	driver2Pin = dpin2;
	pinMode(motor1Pin, OUTPUT);
    pinMode(motor2Pin, OUTPUT);
	pinMode(driver1Pin, OUTPUT);
	pinMode(driver2Pin, OUTPUT);
  }
  void control(int mstate1, int mstate2)
  {
	if (mstate1 = 1)
	{
		mstate1 = 255;
	}
	
	if (mstate2 = 1)
	{
		mstate2 = 255;
	}
	digitalWrite(dpin1, mstate1);	
    digitalWrite(dpin2, mstate2);
  }
};
