/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       SunWater                                                  */
/*    Created:      2024/6/12 22:58:59                                        */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "SWWight/SWWight.h"
#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {
    wait(150, msec);

    logic_runner();
    render_runner();

}

void autonomous(void) {}

void usercontrol(void) {
    // User control code here, inside the loop
    while (1) {
        wait(20, msec);
    }
}

//
// Main will set up the competition functions and callbacks.
//
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
