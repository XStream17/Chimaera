class uart
{
  unsigned int baud_rate = 0;
  char break_char = 0;
  
  public:
  uart(unsigned int BaudRateDivide100, char ending_command)
  {
    baud_rate = BaudRateDivide100;
    break_char = ending_command;
  }

  void initialize()
  {
    Serial.begin(baud_rate * 100);
  }

  char receive_char()
  {
    char char_data = 0;
    
    if (Serial.available() > 0)    
      char_data = Serial.read();

    return char_data;
  }

  char receive_int()
  {
    int int_data = 0;
    
    if (Serial.available() > 0)    
      int_data = Serial.read();

    return int_data;
  }
  
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

  void send_char(char send_data)
  {
    Serial.write(send_data);
  }

  void test()
  {
    char test_data = 0;
    
    if (Serial.available() > 0)
    {
      test_data = Serial.read();
      Serial.write(test_data);
    }
  }
};