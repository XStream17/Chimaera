#include <Servo.h>
class sg90
{
  public:
  int angle = 0;
  int sg90pin;
  Servo servo;
  sg90_init(int servopin)
  {
    sg90pin = servopin;
    servo.attach(servopin);
  }
  void letgo()
  {
      for(angle = 80; angle < 180; angle++)  
        {                                  
          servo.write(angle);                                  
        } 
        delay(50);
  }
  void grab()
  {
      for(angle = 180; angle > 90; angle--)    
        {                                
          servo.write(angle);                 
        } 
        delay(50);
  }

  void whentograb(char char_data)
  {
    switch(char_data){
      Serial.print(char_data);
      case 'G':
      grab();
      break;
        case 'N':
      letgo();
      break;
      default:
      break;
    }
  }
};
