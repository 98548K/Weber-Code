#include "vex.h"

#include "vex.h"

//Variables
int current_time = 60;

//Makes the controller rumble ever 10 seconds
void rumble_timer() {
    if (current_time == 10) {
        Controller1.rumble("--");
    }
    else if (current_time == 20) {
        Controller1.rumble("--");
    }
    else if (current_time == 30) {
        Controller1.rumble("--");
    }
    else if (current_time == 30) {
        Controller1.rumble("--");
    }
    else if (current_time == 40) {
        Controller1.rumble("--");
    }
    else if (current_time == 50) {
        Controller1.rumble("--");
    }


    current_time --;
    wait(1, sec); 
}

//Color sort function
void blue_detected() {
    if (Optical1.color() == blue) {
        //Insert color sort code (outtake/piston)
    }
    else if (Optical1.color() == ClrSkyBlue) {
        //Insert color sort code (outtake/piston)
    }
    else if (Optical1.color() == ClrLightBlue) {
        //Insert color sort code (outtake/piston)
    }
}

void red_detected() {
    if (Optical1.color() == red) {
        //Insert color sort code (outtake/piston)
    }
}

//Auton goal sensor
void goal_stop() {
    if (Optical2.color() == yellow) {
        Drivetrain.stop();
        Clamp.set(false);
        Intakes.spinFor(-1500, deg);
    }
}

//Non-PID/odom drivetrain functions
void reset_both_sides(double SameVelocity) {
    LeftDriveSmart.setVelocity(SameVelocity, pct);
    RightDriveSmart.setVelocity(SameVelocity, pct);
}

void curve_turn(double LeftVelocity,double RightVelocity, double InchesTraveled, double ResetVelocity) {
    LeftDriveSmart.setVelocity(LeftVelocity, pct);
    RightDriveSmart.setVelocity(RightVelocity, pct);
    Drivetrain.driveFor(InchesTraveled, inches, false);
    wait(1, sec);
    Drivetrain.stop();
    reset_both_sides(ResetVelocity);
}
