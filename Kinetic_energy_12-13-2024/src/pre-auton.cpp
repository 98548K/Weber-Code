#include "vex.h"

#include "vex.h"

void pre_auton(void) {
    //Sets motor velocity
    Drivetrain.setDriveVelocity(100, pct);
    Claw_mech.setVelocity(100, pct);
    Intakes.setVelocity(100, pct); 

    //Runs selectable auton
    initial_menu();
}