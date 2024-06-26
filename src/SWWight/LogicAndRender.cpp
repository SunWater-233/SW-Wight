#include "SWWight/SWWight.h"

using namespace vex;

// declare your wight here ↓


int logic() {
    while (true) {
        while (SWWTool.get_start_state()) {
            // write you GUI logic code here ↓
            

            /*
            NOTICE:
                If you wany to make your button pressible or selectable,
                you have to use function started with "determine",
                just like the example below.

                DO rember just use ONE "determine_selected_button()" for ONE
                buttonGroup, and ONE "determine_selected()" for ONE button. And
                the rest of work should be left to "get_selected_state()""

            REASON:
                "determine_selected_button()" has a "waitUtil" function in it,
                which could pause the task and make the button behave
                weird(unable to be seleced, outline flashing....)
            */


            // set the fps(fps setting could be seen in SWWTool.h)
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
            // write you GUI layout code here↓


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
