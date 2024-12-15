#include "vex.h"

void right_red() {
    Drivetrain.setDriveVelocity(20,  pct);
    Clamp.set(true);
    Drivetrain.driveFor(-23, inches);
    Clamp.set(false);
    Intakes.spin(forward);
    wait (1,  sec);
    Drivetrain.turnFor(-55, deg);
    Drivetrain.driveFor(14, inches);
    Drivetrain.turnFor(-100, deg);
    //Claw_mech.spin(forward);
    //Drivetrain.driveFor(10, inches);
}

void left_red() {
    Drivetrain.setDriveVelocity(20,  pct);
    Clamp.set(true);
    Drivetrain.driveFor(-22, inches);
    Clamp.set(false);
    Intakes.spin(forward);
    Drivetrain.turnFor(54, deg);
    Drivetrain.driveFor(8, inches); 
    Drivetrain.turnFor(60, deg);
    Drivetrain.driveFor(9, inches);
    Drivetrain.driveFor(-5, inches);
    Drivetrain.turnFor(-20, deg);
    Drivetrain.driveFor(6, inches);
    Drivetrain.driveFor(-16, inches);
    Drivetrain.turnFor(54, deg);
    Claw_mech.spin(forward);
    Drivetrain.driveFor(7, inches);
}

void right_blue() {
    Drivetrain.setDriveVelocity(20,  pct);
    Clamp.set(true);
    Drivetrain.driveFor(-22, inches);
    Clamp.set(false);
    Intakes.spin(forward);
    Drivetrain.turnFor(-54, deg);
    Drivetrain.driveFor(10, inches); 
    Drivetrain.turnFor(-50, deg);
    Drivetrain.driveFor(8, inches);
    Drivetrain.driveFor(-4, inches);
    Drivetrain.turnFor(10, deg);
    Drivetrain.driveFor(5.5, inches);
    Drivetrain.driveFor(-16, inches);
    Drivetrain.turnFor(-50, deg);
    //Claw_mech.spin(forward);
    //Drivetrain.driveFor(8, inches);
}

void left_blue() {
    Drivetrain.setDriveVelocity(20,  pct);
    Clamp.set(true);
    Drivetrain.driveFor(-25, inches);
    Clamp.set(false);
    Intakes.spin(forward);
    Drivetrain.turnFor(54, deg);
    Drivetrain.driveFor(8, inches);
    Drivetrain.turnFor(100, deg);
    //Claw_mech.spin(forward);
    //Drivetrain.driveFor(10, inches);
}

void skills_auton() {
    //Intakes onto alliance stake and goes for the mobile goal
    Drivetrain.setDriveVelocity(30,  pct);
    Intakes.spinFor(1500, deg, false);
    wait (1, sec);
    Intakes.spinFor(-700, deg, false);
    Drivetrain.driveFor(13, inches);
    Drivetrain.turnFor(52, deg);
    Clamp.set(true);
    Drivetrain.driveFor(-13, inches);
    Clamp.set(false);
    //Collects the 5 rings
    Drivetrain.turnFor(-47, deg);
    Intakes.spin(forward);
    Drivetrain.driveFor(15, inches);
    Drivetrain.turnFor(-60, deg);
//most likely to be changed
    Drivetrain.driveFor(12, inches);
//
    Drivetrain.turnFor(-55, deg);
    Drivetrain.driveFor(24, inches);
    Drivetrain.driveFor(-8, inches);
    Drivetrain.turnFor(60, deg);
    Drivetrain.driveFor(5, inches);
    Drivetrain.turnFor(75, deg);
    Drivetrain.driveFor(-5, inches);
    //Scores goal into corner
    Clamp.set(true);
    Drivetrain.driveFor(5, inches);
    //Turns to position to drive to the goal
    Drivetrain.turnFor(-75, deg);
    //Drives toward wall,  the reverses into goal and clamps on
    Drivetrain.driveFor(4, inches);
    Drivetrain.driveFor(-4,  inches);
    Drivetrain.turnFor(3, deg);
    Drivetrain.driveFor(-49,  inches);
    Clamp.set(false);
}

void right_blue_elims() {
    
}

void right_red_elims() {
    
}

void left_red_elims() {
    Drivetrain.setDriveVelocity(20,  pct);
    Clamp.set(true);
    Drivetrain.driveFor(-22, inches);
    Clamp.set(false);
    Intakes.spin(forward);
    Drivetrain.turnFor(54, deg);
    Drivetrain.driveFor(8, inches); 
    Drivetrain.turnFor(60, deg);
    Drivetrain.driveFor(9, inches);
    Drivetrain.driveFor(-5, inches);
    Drivetrain.turnFor(-20, deg);
    Drivetrain.driveFor(6, inches);
    Drivetrain.driveFor(-16, inches);
    Drivetrain.turnFor(100, deg);
    elevated_intake.set(true);
    Drivetrain.driveFor(20, inches);
    elevated_intake.set(false);
    Drivetrain.driveFor(-5, inches);
}

void left_blue_elims() {
    
}