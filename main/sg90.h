/*{claw. This is the class where we use sg90 as a claw through the use of arduino}
    Copyright (C) {2017}  {XSTREAM17}

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
	

	
/*
	A) SYNTAX:
	claw ObjectName (servopin)
	
	servopin: the number of pin that servo is attached
			  Eg. if your servo is connected to pin 11 then all you need to do is do this "claw Objectname (11)"
			  
	B)	AVAILABLE FUNCTION (FUNCTION PROTOCOL);
	void  init(void);
	void letgo(void);
	void grab(void);
	void whentograb(char char_data);
*/



#include <Servo.h>
class claw
{
	/******************
   * INITIALIZATION *
   ******************/
  /* Public function used for OBJECT DECLARATION */
  public:
    /* Initialization for safety purpose
   * Value to be replaced when declared */
  int angle = 180;
  int clawpin;
  Servo servo;
  claw(int servopin)
  {
    clawpin = servopin;
    servo.attach(clawpin);
  }
  
  
   /*
	 receive data from bluetooth device and decide what to do.
	 if 'G' is received grab() function will be actived. else if 'N' is received letgo() function will be actived instead.
  */
  void whentograb(char char_data)
  {
    switch(char_data){
      case 'G':
      servo.write(80);                
      delay(50);
      break;
      case 'N':          
      servo.write(180);                                   
      delay(50);
      break;
    }
  }
};
