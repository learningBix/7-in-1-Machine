/* Crane - Source Code
   Board - Arduino Uno or MiniCore 168
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

Modular crane; //create a object to access library functions

// initialise the hardware port connections
void setup() {

  crane.steerBotBegin(4); //steering motors connected at port 4
  crane.motorOneBegin(3); // motor 1 for swing connected at port 3
  crane.motorTwoBegin(3); // motor 2 for lift/drop connected at port 3
  crane.bluetoothBegin(1); // bluetooth connected at port 1

}

void loop() {
  //check if a command is received from app via bluetooth
  if (crane.bluetoothCheck() > 0) {
    char serial_cmd = crane.bluetoothRead(); //save the command received

    switch (serial_cmd) { //do action as per the command received
      case MOVE_BOT_FWD :
        crane.steerBotForward(4);
        break;
      case MOVE_BOT_BWD :
        crane.steerBotBackward(4);
        break;
      case MOVE_BOT_LT :
        crane.steerBotLeftAxial(4);
        break;
      case MOVE_BOT_RT :
        crane.steerBotRightAxial(4);
        break;
      case BOT_STOP :
        crane.haltBot(4);
        break;
      case MOTOR_1_CLKWISE :
        crane.motorOneRotateClockwise(3);
        break;
      case MOTOR_1_ACLKWISE :
        crane.motorOneRotateAntiClockwise(3);
        break;
      case MOTOR_1_STOP :
        crane.motorOneHalt(3);
      case MOTOR_2_CLKWISE :
        crane.motorTwoRotateClockwise(3);
        break;
      case MOTOR_2_ACLKWISE :
        crane.motorTwoRotateAntiClockwise(3);
        break;
      case MOTOR_2_STOP :
        crane.motorTwoHalt(3);
    }
  }
}
