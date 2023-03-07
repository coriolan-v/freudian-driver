void readUartDebug() {
  if (Serial.available() > 0)
    processIncomingByte(Serial.read());
}

void sendCommand(int command) {
  if (command == ReturnToZero) {
    Serial.println("Sending command ReturnToZero");
  }
}

const unsigned int MAX_INPUT = 50;
void process_data(const char* data) {
  // for now just display it
  // (but you could compare it to some value, convert to an integer, etc.)
  Serial.println(data);

  if(data == "ReturnToZero"){
    Serial.println("ReturnToZero");
    sendCommand(ReturnToZero);
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

uint16_t calcCRC(char* str) {
  uint16_t crc = 0;                      // starting value as you like, must be the same before each calculation
  for (int i = 0; i < strlen(str); i++)  // for each character in the string
  {
    //crc= _crc16_update (crc, str[i]); // update the crc value
    crc += str[i];
  }
  crc = crc & 0xFF;
  Serial.print("crc: ");
  Serial.println(crc);
  return crc;
}