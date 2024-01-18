#include <Arduino.h>
#include <HardwareSerial.h>

void setup() 
{
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);

  Serial2.printf("%cReady> ", 0x0C);
}

void loop() 
{
  if (Serial2.available())
  {
    Serial.write(Serial2.read());
  }

  if (Serial.available())
  {
    uint8_t c = Serial.read();
    if (c == 0xFE)
    {
      while (Serial.available() == 0) {}
      uint8_t c2 = Serial.read();
      switch (c2)
      {
        case 0x47: 
        {     
          while (Serial.available() < 2) {}
          uint8_t c3 = Serial.read();
          uint8_t c4 = Serial.read();
          Serial2.printf("%c%c%c%c", 0x1F, 0x24, c3, c4);
          break;
        }

        case 0x48:                          // Cursor Home
        {                               
          Serial2.printf("%c", 0x0B);
          break;
        }

        case 0x58:                          // Clear Screen
        {
          Serial2.printf("%c", 0x0C);
          break;
        }

        default:
        {
          Serial2.printf("%c%c", c, c2);
          break;
        }
      }
    }
    else
    {
      Serial2.write(c);
    }
  }
}
