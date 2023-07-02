void readUartDebug() {
  if (Serial.available() > 0)
    processIncomingByte(Serial.read());
}

void sendCommand(int command) {
  if (command == ReturnToZero) {
    Serial.println("Sending command ReturnToZero");
  }
}

uint8_t calculateChecksum(const uint8_t* buffer) {
  int checksum = 0;
  for (int i = 0; i < sizeof(buffer) - 1; i++) {
    checksum += buffer[i];
  }
  checksum = checksum & 0xFF;

  return checksum;
}


const unsigned int MAX_INPUT = 50;
void process_data(const char* data) {
  // for now just display it
  // (but you could compare it to some value, convert to an integer, etc.)
  Serial.print("Received: ");
  Serial.println(data);

  char* pPosition = strchr(data, '/');
  if (pPosition != NULL) {
    // If there is something after the #
    double argument;
    char* token = strtok(data, "/");
    if (token != NULL) {
      //  DEBUG_PRINTLN(second_part);

      token = strtok(NULL, "/");
      argument = constrain(atoi(token), -32000, 32000);

      Serial.print("Argument: ");
      Serial.println(argument);

      if (strcmp(data, SetAcceleration) == 0) {

        int acceleration = argument;
        Serial.print("Received SetAcceleration: ");
        Serial.println(acceleration);

        return;
      }

      if (strcmp(data, RunToAngle) == 0) {

        int newAngle = argument;
        Serial.print("Received newAngle: ");
        Serial.println(newAngle);

        return;
      }

      if (strcmp(data, SetDirection) == 0) {

        int direction = argument;
        Serial.print("Received direction: ");
        Serial.println(direction);

        return;
      }

      if (strcmp(data, SetMaxTorque) == 0) {

        int NewMaxTorque = argument;
        Serial.print("Received SetMaxTorque: ");
        Serial.println(SetMaxTorque);

        return;
      }
    }
  } else {
    Serial.println("No argument received");
    //DEBUG_PRINTLN("Broadcast message");
    //message_is_for_me = true;
  }

  if (strcmp(data, ReturnToZero) == 0) {
    Serial.println("Received ReturnToZero");

    uint8_t buffer[4];
    buffer[0] = 0xe0;
    buffer[1] = 0x94;
    buffer[2] = 0x00;
    //int checksum = (0xe0 + 0x01) & 0xFF;

    int checksum = 0;
    for (int i = 0; i < sizeof(buffer) - 1; i++) checksum += buffer[i];
    checksum = checksum & 0xFF;
    buffer[3] = checksum;

    for (int i = 0; i < sizeof(buffer); i++) {
      Serial.print(i);
      Serial.print(": ");
      Serial.println(buffer[i], HEX);
      DriverPort.print(buffer[i]);
    }

    return;
  }

  if (strcmp(data, StopMotor) == 0) {
    Serial.println("Received StopMotor");

    int bufferSize = 3;
    uint8_t buffer[bufferSize];
    buffer[0] = 0xe0;
    buffer[1] = 0xf7;
    //int checksum = (0xe0 + 0x01) & 0xFF;

    int checksum = 0;
    for (int i = 0; i < sizeof(buffer) - 1; i++) checksum += buffer[i];
    checksum = checksum & 0xFF;
    buffer[bufferSize-1] = checksum;

    for (int i = 0; i < sizeof(buffer); i++) {
      Serial.print(i);
      Serial.print(": ");
      Serial.println(buffer[i], HEX);
      DriverPort.print(buffer[i]);
    }

    return;
  }

  if (strcmp(data, Calibrate) == 0) {
    Serial.println("Received Calibrate");

    int bufferSize = 4;
    uint8_t buffer[bufferSize];
    buffer[0] = 0xe0;
    buffer[1] = 0x80;
    buffer[2] = 0x00;
    //int checksum = (0xe0 + 0x01) & 0xFF;

    int checksum = 0;
    for (int i = 0; i < sizeof(buffer) - 1; i++) checksum += buffer[i];
    checksum = checksum & 0xFF;
    buffer[bufferSize-1] = checksum;

    for (int i = 0; i < sizeof(buffer); i++) {
      Serial.print(i);
      Serial.print(": ");
      Serial.println(buffer[i], HEX);
      DriverPort.print(buffer[i]);
    }


    return;
  }

}  // end of process_data

void processIncomingByte(const byte inByte) {
  static char input_line[MAX_INPUT];
  static unsigned int input_pos = 0;

  switch (inByte) {

    case '\n':                    // end of text
      input_line[input_pos] = 0;  // terminating null byte

      // terminator reached! process input_line here ...
      process_data(input_line);

      // reset buffer for next time
      input_pos = 0;
      break;

    case '\r':  // discard carriage return
      break;

    default:
      // keep adding if not full ... allow for terminating null byte
      if (input_pos < (MAX_INPUT - 1))
        input_line[input_pos++] = inByte;
      break;

  }  // end of switch

}  // end of processIncomingByte

// uint16_t calcCRC(char* str) {
//   uint16_t crc = 0;                      // starting value as you like, must be the same before each calculation
//   for (int i = 0; i < strlen(str); i++)  // for each character in the string
//   {
//     //crc= _crc16_update (crc, str[i]); // update the crc value
//     crc += str[i];
//   }
//   crc = crc & 0xFF;
//   Serial.print("crc: ");
//   Serial.println(crc);
//   return crc;
// }