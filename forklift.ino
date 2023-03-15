/* Forklift - Source Code
   Board - MiniCore 168 or Arduino Uno
*/

#include <modular.h> // include modular library

// bluetooth commands for the mobile app - bixchamp
#define MOVE_BOT_FWD 0xB0
#define MOVE_BOT_BWD 0xB1
#define MOVE_BOT_LT 0xB2
#define MOVE_BOT_RT 0xB3
#define BOT_STOP 0xB4
#define MOTOR_1_CLKWISE 0xB5
#define MOTOR_1_ACLKWISE 0xB6
#define MOTOR_1_STOP 0xB7

Modular forklift; //create a object to access library functions

// initialise the hardware port connections
void setup() {

  forklift.steerBotBegin(4); //steering motors connected at port 4
  forklift.motorOneBegin(3); // motor 1 for lift/drop, connected at port 3
  forklift.bluetoothBegin(1); // bluetooth connected at port 1

}

void loop() {
  //check if a command is received from app via bluetooth
  if (forklift.bluetoothCheck() > 0) {
    char serial_cmd = forklift.bluetoothRead(); //save the command received

    switch (serial_cmd) { //do action as per the command received
      case MOVE_BOT_FWD :
        forklift.steerBotForward(4);
        break;
      case MOVE_BOT_BWD :
        forklift.steerBotBackward(4);
        break;
      case MOVE_BOT_LT :
        forklift.steerBotLeftAxial(4);
        break;
      case MOVE_BOT_RT :
        forklift.steerBotRightAxial(4);
        break;
      case BOT_STOP :
        forklift.haltBot(4);
        break;
      case MOTOR_1_CLKWISE :
        forklift.motorOneRotateClockwise(3);
        break;
      case MOTOR_1_ACLKWISE :
        forklift.motorOneRotateAntiClockwise(3);
        break;
      case MOTOR_1_STOP :
        forklift.motorOneHalt(3);
    }
  }
}
