#include "vex.h"

#include "vex.h"

bool clamped = false;

void usercontrol(void) {
  while (1) {
    task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);

     //Manuel clamp toggle
      if (Controller1.ButtonY.pressing()) {
        if (clamped == true) {
          clamped = false;
          wait(.22, sec);
        }
        else if (clamped == false) {
          clamped = true;
          wait(.22, sec);
        }
      }
      //Activates clamp
      Clamp.set(clamped);
    }

    wait(20, msec);
  }
