/* Army Tank - Source Code
   Board - Mi/niCore 168 or Arduino Uno
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

Modular tank; //create a object to access library functions

// initialise the hardware port connections
void setup() {

  tank.steerBotBegin(4); //steering motors connected at port 4
  tank.motorOneBegin(3); // motor 1 for swing, connected at port 3
  tank.motorTwoBegin(3); // motor 2 for shoot/reload, connected at port 3
  tank.bluetoothBegin(1); // bluetooth connected at port 1

}

void loop() {
  //check if a command is received from app via bluetooth
  if (tank.bluetoothCheck() > 0) {
    char serial_cmd = tank.bluetoothRead(); //save the command received

    switch (serial_cmd) { //do action as per the command received
      case MOVE_BOT_FWD :
        tank.steerBotForward(4);
        break;
      case MOVE_BOT_BWD :
        tank.steerBotBackward(4);
        break;
      case MOVE_BOT_LT :
        tank.steerBotLeftAxial(4);
        break;
      case MOVE_BOT_RT :
        tank.steerBotRightAxial(4);
        break;
      case BOT_STOP :
        tank.haltBot(4);
        break;
      case MOTOR_1_CLKWISE :
        tank.motorOneRotateClockwise(3);
        break;
      case MOTOR_1_ACLKWISE :
        tank.motorOneRotateAntiClockwise(3);
        break;
      case MOTOR_1_STOP :
        tank.motorOneHalt(3);
      case MOTOR_2_CLKWISE :
        tank.motorTwoRotateClockwise(3);
        break;
      case MOTOR_2_ACLKWISE :
        tank.motorTwoRotateAntiClockwise(3);
        break;
      case MOTOR_2_STOP :
        tank.motorTwoHalt(3);
    }
  }
}
