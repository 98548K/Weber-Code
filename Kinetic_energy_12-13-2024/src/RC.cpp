#include "vex.h"
#include <iostream>
#include <cmath>

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;
bool Controller1RightShoulderControlMotorsStopped = true;
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

//Autoset clamp
int current_velocity = 100;



// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
    //float liftPositions[3] = {
    //2.9,
    //13,      // Bottom angle
    //25,    // Ring loader angle
    
    //};



    //int liftTarget = 0;

    //void toggleLiftUpState(); {
    //liftTarget++;

    //if (liftTarget == 4) {
        //liftTarget = 1;
    //}
//}

    //void liftDown(); {
        //int liftTarget = 0;

    //}

    //Controller1.ButtonR1.pressing(toggleLiftUpState);
    //Controller1.ButtonR2.pressing(liftDown);
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
        if(RemoteControlCodeEnabled) {
            
    //float targetAngle = liftPositions[liftTarget];
    //float liftError = targetAngle - Claw_tracking.angle(degrees);




 //if ((liftError) >= 1) {
    //Claw_mech.spin(forward, liftError * 1.8, percent);
  //} else {
    //Claw_mech.stop();
  //}

  //Claw_mech.spin(reverse, liftError * 1.8, percent);
//
  //std::cout << "Angle: " << Claw_tracking.angle(degrees) << std::endl;
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3
      // right = Axis2
      int drivetrainLeftSideSpeed = Controller1.Axis3.position();
      int drivetrainRightSideSpeed = Controller1.Axis2.position();
      
      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          LeftDriveSmart.stop();
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          RightDriveSmart.stop();
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveSmart.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveSmart.spin(forward);
      }
      // check the ButtonL1/ButtonL2 status to control Intakes
      if (Controller1.ButtonL1.pressing()) {
        Intakes.spin(forward);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        Intakes.spin(reverse);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        Intakes.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1LeftShoulderControlMotorsStopped = true;
      }
      // check the ButtonR1/ButtonR2 status to control Claw_mech
      if (Controller1.ButtonR1.pressing()) {
        Claw_mech.setVelocity(100,pct);
        Claw_mech.spin(forward);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR2.pressing()) {
        Claw_mech.setVelocity(100,pct);
        Claw_mech.spin(reverse);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (!Controller1RightShoulderControlMotorsStopped) {
        Claw_mech.setVelocity(100,pct);
        Claw_mech.stop(brake);
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1RightShoulderControlMotorsStopped = true;
      }

     






    if (Controller1.ButtonRight.pressing()) {
        
        Claw_mech.setVelocity(20, pct);
        if (Claw_tracking.position(degrees) > 40 && Claw_tracking.position(degrees) < 47) {
            Claw_mech.setVelocity(3.5, pct);
            if (Claw_tracking.position(degrees) > 43.7 && Claw_tracking.position(degrees) < 44.1) {
                Claw_mech.setVelocity(1, pct);
                if (Claw_tracking.position(degrees) == 43.9) {
                    Claw_mech.stop(hold);
                }
            }
        }
        else if (Claw_tracking.position(degrees) > 50) {
            Claw_mech.spin(reverse);
        }
        else if (Claw_tracking.position(degrees) < 50) {
            Claw_mech.spin(forward);
        }


      //sort of working
      /*while (Claw_tracking.position(degrees) > 15) {
        Claw_mech.setVelocity(current_velocity,pct);
        //current_velocity --;
        
        Claw_mech.spinFor(claw_error,deg);
      }
      Claw_mech.stop(hold);*/

      //not working
      /*while (Claw_tracking.position(degrees) < 15) {
        Claw_mech.setVelocity(current_velocity,pct);
        //current_velocity --;
        Claw_mech.spinFor(claw_error,deg);
      }
      Claw_mech.stop(hold);*/
    }



    // wait before repeating the process
    wait(5, msec);
  }
  return 0;
  }
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  //task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}