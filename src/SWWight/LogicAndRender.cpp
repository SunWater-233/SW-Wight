#include "SWWight/SWWight.h"

// declare some functions here
int logic();
int render();

namespace SWWight {
void logic_runner() { vex::task SWWLogic(logic); }
void render_runner() { vex::task SWWrender(render); }
}  // namespace SWWight

using namespace SWWight;

// declare your wight here ↓
button buttonTest(100, 100, 50, 50, SELECT);
graph armMotorEffGraph(50, 220, 300, 200, LINE, PASS);
panel armMotorEffPanel(350, 70, 60, 0, 100);

// If you don't kown what the constructors↑ above mean,
// check the corresponding header files.

int logic() {
    while (true) {
        while (SWWTool.get_start_state()) {
            // write you GUI logic code here ↓
            buttonTest.determine_selected();
            /*
            NOTICE:
                If you want to make your button pressible or selectable,
                you have to use function started with "determine",
                just like the example below.

                DO rember just use ONE "determine_selected_button()" for ONE
                buttonGroup, and ONE "determine_selected()" for ONE button. And
                the rest of work should be left to "get_selected_state()""

            REASON:
                "determine_selected_button()" has a "waitUtil" function in it,
                which could pause the task and make the button behave
                weird(unable to be seleced, outline flashing....) if you use
                mutipule "determine" functions.
            */
        

            // set the fps(fps setting could be seen in SWWTool.h)
            wait(SWWTool.get_frame_pause_time(), msec);
        }
        wait(SWWTool.get_frame_pause_time(), msec);
    }
}

// If you want to display your widgets, write your render code here↓
int render() {
    // set your wight here ↓
    armMotorEffGraph.set_graph_color(SWWColor.sun_flower);
    

    while (true) {
        while (SWWTool.get_start_state()) {
            SWWBrain.Screen.clearScreen();
            // write you GUI layout code here↓
            armMotorEffGraph.display();
            armMotorEffPanel.display();
            buttonTest.display();

            // make sure everything render at the same time
            SWWBrain.Screen.render();
            // set the fps(fps setting could be seen in SWWTool.h)
            wait(SWWTool.get_frame_pause_time(), msec);
        }
        wait(SWWTool.get_frame_pause_time(), msec);
    }
}
