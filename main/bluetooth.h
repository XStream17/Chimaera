/*{uart. This is the class that allow arduino to interact with HC-05}
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

/* A) SYNTAX:
 *    uart ObjectName (BaudRate, EndingCommand)
 * 
 *    BaudRate: Data transmission speed
 *              Replace with the desire baud rate value *DIVIDED BY 100
 *              Eg. 9600 => BaudRate = 96
 * 
 *    EndingCommand: Indicator of end of string
 *                   Replace with the desire ending command / break character
 *                   ESSENTIAL for function receive_value()
 *                   Eg. If EndingCommand = 'a'
 *                       Incoming Data = 12a34
 *                       receive_value() returns 12
 * 
 * 
 * B) AVAILABLE FUNCTION (FUNCTION PROTOCOL):
 *    void send_char(char send_data);
 *    char receive_char(void);
 *    int receive_int(void);
 *    int receive_value(void);
 *    void test(void);
 * 
 * 
 * C) NOTE:
 *    BaudRate is stored in a 16-bit (unsigned int) variable
 *    unsigned int variable can store value from 0 to 65535
 *    Baud rate can go from 300 to 115200 or even higher
 *    Since the baud rate will always be a multiple of 100
 *    It is more efficient to store the value after dividing it by 100
 * 
 *    Keep in mind:
 *    Data transmission of UART / Serial / TX & RX is in ASCII form
 */
 
 
 
 class bluetooth
{
  /* Initialization for safety purpose
   * Value to be replaced when declared */
  unsigned int baud_rate = 0;
  char break_char = 0;
  
  
   /******************
   * INITIALIZATION *
   ******************/
  /* Public function used for OBJECT DECLARATION */
  public:
  bluetooth(unsigned int BaudRateDivide100, char ending_command)
  {
    baud_rate = BaudRateDivide100;
    break_char = ending_command;
    Serial.begin(baud_rate * 100);
  }
  
   
   /***********
   * RECEIVE *
   ***********/
  /* Receive single byte of data and return CHAR
   * Send: 'A' (Hex: 41, Bin: 0100 0001) 
   * Receive: 'A' (Hex: 41, Bin: 0100 0001) */
  char receive_char()
  {
    char char_data;
    
    if (Serial.available() > 0){    
      char_data = Serial.read();
    }

    return char_data;
  }

  
  
  /* Receive single byte of data and return INT (its respective decimal form)
   * Send: 'A' (Hex: 41; Bin: 0100 0001) 
   * Receive: 65 (Hex: 41; Bin: 0100 0001) */
  char receive_int()
  {
    int int_data = 0;
    
    if (Serial.available() > 0)    
      int_data = Serial.read();

    return int_data;
  }
  
  
  
  /* Receive data until it meets the ending command / break character
   * Return the processed VALUE
   * Eg. EndingCommand = 'z'
   * Send: "12z3" (Hex: 31,32,7A,33; Bin: 0011 0001,0011 0010,0111 1010,0011 0011)
   * Receive: 12 (Hex: C, Bin: 1100) */
  int receive_value()
  {
    int value = 0;
    char receivevalue = '0';

    while (receivevalue != break_char)
    {
      value = value * 10;
      receivevalue -= 48;
      value += receivevalue;
      receivevalue = Serial.read();
    }

    return value;
  }

   /********
   * SEND *
   ********/
  /* Send single byte of data */
  void send_char(char send_data)
  {
    Serial.write(send_data);
  }
  
  /*********
   * DEBUG *
   *********/
  /* For TESTING / DEBUGGING
   * Send whatever it receives */
  void test()
  {
    char test_data = 0;
    
    if (Serial.available() > 0)
    {
      delay(3);
      test_data = Serial.read();
      Serial.write(test_data);
    }
  }
};
