/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       jgreco22                                                  */
/*    Created:      Wed Jan 13 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// frontLeftDrive       motor         1               
// backLeftDrive        motor         11              
// frontRightDrive      motor         10              
// backRightDrive       motor         20              
// intakeLeft           motor         16              
// intakeRight          motor         12              
// frontManip           motor         8               
// backManip            motor         3               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "functionsLibrary.h"
using namespace vex;
competition Competition;

void pre_auton(void){}

void autonomous(void) {
  aProgramming();
}

void usercontrol(void) {
  while(true){

    //Drive
    frontLeftDrive.spin(vex::directionType::fwd, Controller1.Axis3.value()-Controller1.Axis1.value()+Controller1.Axis4.value(), vex::velocityUnits::pct);
    backLeftDrive.spin(vex::directionType::fwd, Controller1.Axis3.value()-Controller1.Axis1.value()-Controller1.Axis4.value(), vex::velocityUnits::pct);
    frontRightDrive.spin(vex::directionType::fwd, Controller1.Axis3.value()+Controller1.Axis1.value()-Controller1.Axis4.value(), vex::velocityUnits::pct);
    backRightDrive.spin(vex::directionType::fwd, Controller1.Axis3.value()+Controller1.Axis1.value()+Controller1.Axis4.value(), vex::velocityUnits::pct);

    //Intake
    if (Controller1.ButtonR1.pressing()){
      intakeLeft.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
      intakeRight.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
      frontManip.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);//experimental
      backManip.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }
    else if (Controller1.ButtonR2.pressing()){
      intakeLeft.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
      intakeRight.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
      frontManip.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
      backManip.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }
    else{
      intakeLeft.stop(hold);
      intakeRight.stop(hold);
      frontManip.stop(hold);
      backManip.stop(hold);
    }

    //Manip   
    wait(20, msec); 
  }
}
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
