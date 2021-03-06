#pragma config(Sensor, S1,     HTANG,               sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: hitechnic-angle-test1.c 123 2012-11-02 16:35:15Z xander $
 */

/**
 * hitechnic-angle.h provides an API for the HiTechnic Angle Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: Removed common.h from includes
 *
 * Credits:
 * - Big thanks to HiTechnic for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 3.54 AND HIGHER.
 * Xander Soldaat (xander_at_botbench.com)
 * date 20 February 2011
 * version 0.2
 */

#include "drivers/hitechnic-angle.h"

task main () {
  nNxtButtonTask  = -2;
  nxtDisplayCenteredTextLine(0, "HiTechnic");
  nxtDisplayCenteredBigTextLine(1, "Angle");
  nxtDisplayCenteredTextLine(3, "Test 1");
  nxtDisplayCenteredTextLine(5, "Connect sensor");
  nxtDisplayCenteredTextLine(6, "to S1");
  wait1Msec(2000);

  eraseDisplay();
  nxtDisplayCenteredTextLine(0, "HiTechnic Angle");
  nxtDisplayTextLine(1, "-------------------");
  nxtDisplayTextLine(5, "-------------------");
  while (true) {
    // If the left button is pressed, set the 0 point to the current angle
    if (nNxtButtonPressed == kLeftButton) {
      HTANGresetAngle(HTANG);
      while (nNxtButtonPressed != kNoButton) EndTimeSlice();

    // Reset the total accumulated angle to 0
    } else if (nNxtButtonPressed == kRightButton) {
      HTANGresetAccumulatedAngle(HTANG);
      while (nNxtButtonPressed != kNoButton) EndTimeSlice();
    }

    // Read the current angle, accumulated angle and RPM and display them
    nxtDisplayTextLine(2, "Ang: %7d deg", HTANGreadAngle(HTANG));
    nxtDisplayTextLine(3, "Tot: %7d deg", HTANGreadAccumulatedAngle(HTANG));
    nxtDisplayTextLine(4, "RPM: %7d", HTANGreadRPM(HTANG));
    nxtDisplayTextLine(6, " < Set angle");
    nxtDisplayTextLine(7, "   Reset total >");
    wait1Msec(50);
  }
}


/*
 * $Id: hitechnic-angle-test1.c 123 2012-11-02 16:35:15Z xander $
 */
