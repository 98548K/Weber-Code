//External files
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Manual files
#include "v5.h"
#include "v5_vcs.h"
#include "robot-config.h"
#include "RC.h"
#include "pre-auton.h"
#include "autonomous.h"
#include "user-control.h"
#include "auton-selector.h"
#include "autons.h"
#include "other-functions.h"
#include "claw-PID.h"


#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)