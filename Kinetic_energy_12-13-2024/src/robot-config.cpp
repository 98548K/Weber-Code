#include "vex.h"

#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LF = motor(PORT14, ratio18_1, true);
motor LM = motor(PORT4, ratio18_1, true);
motor LB = motor(PORT2, ratio18_1, true);
motor_group LeftDriveSmart = motor_group(LF, LM, LB);
motor RF = motor(PORT13, ratio18_1, false);
motor RM = motor(PORT9, ratio18_1, false);
motor RB = motor(PORT12, ratio18_1, false);
motor_group RightDriveSmart = motor_group(RF, RM, RB);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
inertial Inertial1 = inertial(PORT15);
rotation Front_tracking = rotation(PORT8, false);
rotation Side_tracking = rotation(PORT17, false);
rotation Claw_tracking = rotation(PORT16, false);
optical Optical1 = optical(PORT18);
optical Optical2 = optical(PORT5);
motor Fintake = motor(PORT20, ratio18_1, true);
motor Bintake = motor(PORT6, ratio18_1, true);
motor_group Intakes = motor_group(Fintake, Bintake);
motor Claw_mech = motor(PORT19, ratio18_1, false);
digital_out Clamp = digital_out(Brain.ThreeWirePort.H);
digital_out elevated_intake = digital_out(Brain.ThreeWirePort.A);

