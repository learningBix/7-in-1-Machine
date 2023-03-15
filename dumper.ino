/* Dumper - Source Code
   Board - MiniCore 168 or Arduino Uno
*/

#include <modular.h> // include modular library

// bluetooth commands for the mobile app - bixchamp
#define MOVE_BOT_FWD 0xB0
#define MOVE_BOT_BWD 0xB1
#define MOVE_BOT_LT 0xB2
#define MOVE_BOT_RT 0xB3
#define BOT_STOP 0xB4
#define SERVO_1_ANGLE 0xBB

Modular dumper; //create a object to access library functions

// initialise the hardware port connections
void setup() {

  dumper.steerBotBegin(4); //steering motors connected at port 4
  dumper.servoOneBegin(3); //servo motor 1 for dump action, connected at port3
  dumper.bluetoothBegin(1); // bluetooth connected at port 1

}

void loop() {
  //check if a command is received from app via bluetooth
  if (dumper.bluetoothCheck() > 0) {
    char message = dumper.bluetoothRead(); //save the command received

    switch (message) { //do action as per the command received
      case MOVE_BOT_FWD :
        dumper.steerBotForward(4);
        break;
      case MOVE_BOT_BWD :
        dumper.steerBotBackward(4);
        break;
      case MOVE_BOT_LT :
        dumper.steerBotLeftAxial(4);
        break;
      case MOVE_BOT_RT :
        dumper.steerBotRightAxial(4);
        break;
      case BOT_STOP :
        dumper.haltBot(4);
        break;
      case SERVO_1_ANGLE :
        while (dumper.bluetoothCheck() <= 0); //wait for the servo angle value from the app
        message = dumper.bluetoothRead(); //save servo angle received from bluetooth
        dumper.servoOneMove(message); //set angle with the value received
        break;
    }
  }
}
