using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor frontLeftDrive;
extern motor backLeftDrive;
extern motor frontRightDrive;
extern motor backRightDrive;
extern motor intakeLeft;
extern motor intakeRight;
extern motor frontManip;
extern motor backManip;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
