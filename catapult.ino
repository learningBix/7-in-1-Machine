/* Catapult - Source Code
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
#define MOTOR_2_CLKWISE 0xB8
#define MOTOR_2_ACLKWISE 0xB9
#define MOTOR_2_STOP 0xBA

Modular catapult; //create a object to access library functions

// initialise the hardware port connections
void setup() {

  catapult.steerBotBegin(4); //steering motors connected at port 4
  catapult.motorOneBegin(3); // motor 1 for throw action, connected at port 3
  catapult.bluetoothBegin(1); // bluetooth connected at port 1

}

void loop() {
  //check if a command is received from app via bluetooth
  if (catapult.bluetoothCheck() > 0) {
    char serial_cmd = catapult.bluetoothRead(); //save the command received

    switch (serial_cmd) { //do action as per the command received
      case MOVE_BOT_FWD :
        catapult.steerBotForward(4);
        break;
      case MOVE_BOT_BWD :
        catapult.steerBotBackward(4);
        break;
      case MOVE_BOT_LT :
        catapult.steerBotLeftAxial(4);
        break;
      case MOVE_BOT_RT :
        catapult.steerBotRightAxial(4);
        break;
      case BOT_STOP :
        catapult.haltBot(4);
        break;
      case MOTOR_1_CLKWISE :
        catapult.motorOneRotateClockwise(3);
        break;
      case MOTOR_1_ACLKWISE :
        catapult.motorOneRotateAntiClockwise(3);
        break;
      case MOTOR_1_STOP :
        catapult.motorOneHalt(3);
    }
  }
}
