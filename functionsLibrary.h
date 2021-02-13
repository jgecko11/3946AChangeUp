#include "vex.h"
/*-------------Autonomous Functions----------------*/
void aDrive(float distance, int speed){
  frontLeftDrive.startRotateFor(distance, vex::rotationUnits::deg, speed, vex::velocityUnits::pct);
  backLeftDrive.startRotateFor(distance, vex::rotationUnits::deg, speed, vex::velocityUnits::pct);
  frontRightDrive.startRotateFor(distance, vex::rotationUnits::deg, speed, vex::velocityUnits::pct);
  backRightDrive.startRotateFor(distance, vex::rotationUnits::deg, speed, vex::velocityUnits::pct);
  //this section will need some adjusting
  float waitFactor = 2600; 
  int sleepAmt = abs((int)(distance/speed*waitFactor));
  vex::task::sleep(sleepAmt);
}

void aTurn(float deg, int speed, bool direction){
  //false is left, true is right
  if(direction == true){//Right Turn. The negative signs will need to be fixed
    frontLeftDrive.startRotateFor(deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
    backLeftDrive.startRotateFor(deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
    frontRightDrive.startRotateFor(-deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
    backRightDrive.startRotateFor(-deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
  }
  else{//Left Turn
    frontLeftDrive.startRotateFor(-deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
    backLeftDrive.startRotateFor(-deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
    frontRightDrive.startRotateFor(deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
    backRightDrive.startRotateFor(deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
  }
  //Automatically calculated wait factor based on inches, speed, and a tested multiplier. This will also need some adjusting
  float waitFactor = 38000;
  int sleepAmt = abs((int)(deg/speed*waitFactor));
  vex::task::sleep(sleepAmt);
}

void aStrafe(float deg, int speed, bool direction){
  //false is left, true is right
  if(direction == true){//Right Strafe. The negative signs will need to be fixed
    frontLeftDrive.startRotateFor(-deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
    backLeftDrive.startRotateFor(deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
    frontRightDrive.startRotateFor(-deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
    backRightDrive.startRotateFor(deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
  }
  else{//Left Turn
    frontLeftDrive.startRotateFor(deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
    backLeftDrive.startRotateFor(-deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
    frontRightDrive.startRotateFor(deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
    backRightDrive.startRotateFor(-deg*360,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);

  //Automatically calculated wait factor based on inches, speed, and a tested multiplier. This will also need some adjusting
  float waitFactor = 38000;
  int sleepAmt = abs((int)(deg/speed*waitFactor));
  vex::task::sleep(sleepAmt);
}
}
/**
void aIntake(float speed, int duration){
  IntakeLeft.startRotateFor(duration,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
  IntakeRight.startRotateFor(duration,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
  
}

void aScore(float speed, int duration){
  BackManip.startRotateFor(duration,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
  FrontManip.startRotateFor(duration,vex::rotationUnits::deg,speed,vex::velocityUnits::pct);
  vex::task::sleep(duration*10);
}
**/

//AUTONS//

void aProgramming (){
  backManip.spin(fwd,100,vex::velocityUnits::pct);
  frontManip.spin(fwd,100,vex::velocityUnits::pct);//score first ball. All of this is arbitrary btw
  vex::task::sleep(250);
  aStrafe(15,75,true);//strafe right
  aTurn(180,75,true); //turn right 180 to line up with ball
  intakeLeft.spin(fwd,100,vex::velocityUnits::pct);
  intakeRight.spin(fwd,100,vex::velocityUnits::pct);
  aDrive(10,75);//intake and drive forward
  intakeLeft.stop(hold);
  intakeRight.stop(hold);
  vex::task::sleep(250);
  aTurn(30,75,true);//turn right to line up with goal
  aDrive(25,75);//drive towards goal
  backManip.spin(fwd,100,vex::velocityUnits::pct);
  frontManip.spin(fwd,100,vex::velocityUnits::pct);//score
  vex::task::sleep(250);
  aDrive(-5,75); //backup slightly so we do not interfere with the goal
  aStrafe(20,75,true); //strafe right towards the home line
  aTurn(30,75,false); //turn to face the ball
  intakeLeft.spin(fwd,100,vex::velocityUnits::pct);
  intakeRight.spin(fwd,100,vex::velocityUnits::pct);
  aDrive(150,75); //intake ball and drive forward
  intakeLeft.stop(hold);
  intakeRight.stop(hold);
  vex::task::sleep(250);
  aTurn(30,75,true);//turn right to line up with goal 
  aDrive(25,75);//drive towards goal
  backManip.spin(fwd,100,vex::velocityUnits::pct);
  frontManip.spin(fwd,100,vex::velocityUnits::pct);//score
  vex::task::sleep(250);
  //lets hope it fucking works.
  //46to 65
  aDrive(-5,75); //back up
  aTurn(120,75,false);//turn towards ball
  intakeLeft.spin(fwd,100,vex::velocityUnits::pct);
  intakeRight.spin(fwd,100,vex::velocityUnits::pct);
  aDrive(200,75);
  intakeLeft.stop(hold);
  intakeRight.stop(hold);
  vex::task::sleep(250);
  aTurn(120,75,true);//turn right towards goal
  aDrive(15,75);
  backManip.spin(fwd,100,vex::velocityUnits::pct);
  frontManip.spin(fwd,100,vex::velocityUnits::pct);
  vex::task::sleep(250);//score
  aDrive(-50,75);
  aTurn(90,75,false);
  intakeLeft.spin(fwd,100,vex::velocityUnits::pct);
  intakeRight.spin(fwd,100,vex::velocityUnits::pct);
  aDrive(100,75);
  intakeLeft.stop(hold);
  intakeRight.stop(hold);
  vex::task::sleep(250);
  aTurn(60,75,true);
  aDrive(70,75);
  backManip.spin(fwd,100,vex::velocityUnits::pct);
  frontManip.spin(fwd,100,vex::velocityUnits::pct);
  vex::task::sleep(250);


}
