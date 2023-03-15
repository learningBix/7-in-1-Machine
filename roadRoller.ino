/* Road Roller - Source Code
   Board - MiniCore 168 or Arduino Uno
*/

#include <modular.h> // include modular library

// bluetooth commands for the mobile app - bixchamp
#define MOVE_BOT_FWD 0xB0
#define MOVE_BOT_BWD 0xB1
#define MOVE_BOT_LT 0xB2
#define MOVE_BOT_RT 0xB3
#define BOT_STOP 0xB4

Modular roller; //create a object to access library functions

// initialise the hardware port connections
void setup() {

  roller.steerBotBegin(4); //steering motors connected at port 4
  roller.bluetoothBegin(1); // bluetooth connected at port 1

}

void loop() {
  //check if a command is received from app via bluetooth
  if (roller.bluetoothCheck() > 0) {
    char serial_cmd = roller.bluetoothRead(); //save the command received

    switch (serial_cmd) { //do action as per the command received
      case MOVE_BOT_FWD :
        roller.steerBotForward(4);
        break;
      case MOVE_BOT_BWD :
        roller.steerBotBackward(4);
        break;
      case MOVE_BOT_LT :
        roller.steerBotLeftAxial(4);
        break;
      case MOVE_BOT_RT :
        roller.steerBotRightAxial(4);
        break;
      case BOT_STOP :
        roller.haltBot(4);
        break;
    }
  }
}
