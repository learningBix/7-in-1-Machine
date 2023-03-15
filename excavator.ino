/* Excavator - Source Code
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
#define SERVO_2_ANGLE 0xBC
#define SERVO_3_ANGLE 0xBD
#define SERVO_4_ANGLE 0xBE

Modular excavator; //create a object to access library functions

// initialise the hardware port connections
void setup() {

  excavator.steerBotBegin(4); //steering motors connected at port 4
  excavator.servoOneBegin(3); //servo motor 1 for swing, connected at port3
  excavator.servoTwoBegin(3); //servo motor 2 for bucket, connected at port3
  excavator.servoThreeBegin(3); //servo motor 3 for boom, connected at port3
  excavator.servoFourBegin(3); //servo motor 4 for arm, connected at port3
  excavator.bluetoothBegin(1); // bluetooth connected at port 1

}

void loop() {
  //check if a command is received from app via bluetooth
  if (excavator.bluetoothCheck() > 0) {
    char message = excavator.bluetoothRead(); //save the command received

    switch (message) { //do action as per the command received
      case MOVE_BOT_FWD :
        excavator.steerBotForward(4);
        break;
      case MOVE_BOT_BWD :
        excavator.steerBotBackward(4);
        break;
      case MOVE_BOT_LT :
        excavator.steerBotLeftAxial(4);
        break;
      case MOVE_BOT_RT :
        excavator.steerBotRightAxial(4);
        break;
      case BOT_STOP :
        excavator.haltBot(4);
        break;
      case SERVO_1_ANGLE :
        while (excavator.bluetoothCheck() <= 0); //wait for the servo angle value from the app
        message = excavator.bluetoothRead(); //save servo angle received from bluetooth
        excavator.servoOneMove(message); //set angle with the value received
        break;
      case SERVO_2_ANGLE :
        while (excavator.bluetoothCheck() <= 0); //wait for the servo angle value from the app
        message = excavator.bluetoothRead(); //save servo angle received from bluetooth
        excavator.servoTwoMove(message); //set angle with the value received
        break;
      case SERVO_3_ANGLE :
        while (excavator.bluetoothCheck() <= 0); //wait for the servo angle value from the app
        message = excavator.bluetoothRead(); //save servo angle received from bluetooth
        excavator.servoThreeMove(message); //set angle with the value received
        break;
      case SERVO_4_ANGLE :
        while (excavator.bluetoothCheck() <= 0); //wait for the servo angle value from the app
        message = excavator.bluetoothRead(); //save servo angle received from bluetooth
        excavator.servoFourMove(message); //set angle with the value received
        break;
    }
  }
}
