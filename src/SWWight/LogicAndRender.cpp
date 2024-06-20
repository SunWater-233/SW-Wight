#include "SWWight/SWWight.h"

using namespace vex;

// declare your wight here ↓


int logic() {
    while (true) {
        while (SWWTool.get_start_state()) {
            // write you GUI logic code here

            wait(SWWTool.get_frame_pause_time(), msec);
        }
        wait(SWWTool.get_frame_pause_time(), msec);
    }
}

int render() {
    // set your wight here ↓

    while (true) {
        while (SWWTool.get_start_state()) {
            Brain.Screen.clearScreen();
            // write you GUI layout code here



            // make sure everything render at the same time
            Brain.Screen.render();
            // set the fps(fps setting could be seen in SWWTool.h)
            wait(SWWTool.get_frame_pause_time(), msec);
        }
        wait(SWWTool.get_frame_pause_time(), msec);
    }
}

void logic_runner() { vex::task SWWLogic(logic); }
void render_runner() { vex::task SWWrender(render); }
