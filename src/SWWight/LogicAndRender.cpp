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
button TestButton(420, 5, 50, 50, PRESS);
button TestButton_1(420, 70, 50, 50, SELECT);
button TestButton_2(420, 135, 50, 50, SELECT);

std::vector<button*> a = {&TestButton, &TestButton_1, &TestButton_2};
buttonGroup TestButtonGroup(a, 1);

graph TestGraph(180, 180, 180, 150, LINE, PASS);

panel TestPanel(20, 20, 50, -100, 100);

slider TestSlider(30, 150, 120, 15, HORIZONTAL, 0, 100);

// If you don't kown what the constructors↑ above mean,
// check the corresponding header files.

int logic() {
    while (true) {
        while (SWWTool.get_start_state()) {
            // write you GUI logic code here ↓
            TestPanel.set_panel_data(TestMotor.velocity(pct));
            TestGraph.add_data(Brain.timer(msec), TestMotor.velocity(rpm));

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

            TestButtonGroup.determine_selected_button();
            if (TestButton.determine_pressing()) {
                TestMotor.spin(forward, TestSlider.get_slider_value(), pct);
            } else {
                if (TestButton_1.get_selected_state() &&
                    TestButton_2.get_selected_state()) {
                    TestMotor.spin(forward, 100, pct);
                } else if (TestButton_1.get_selected_state()) {
                    TestMotor.spin(forward, 50, pct);
                } else if (TestButton_2.get_selected_state()) {
                    TestMotor.spin(forward, 75, pct);
                } else {
                    TestMotor.stop(coast);
                }
            }

            // set the fps(fps setting could be seen in SWWTool.h)
            wait(SWWTool.get_frame_pause_time(), msec);
        }
        wait(SWWTool.get_frame_pause_time(), msec);
    }
}

// If you want to display your widgets, write your render code here↓
int render() {
    // set your wight here ↓
    TestPanel.set_data_label_font(mono20);
    TestGraph.set_graph_color(SWWColor.sun_flower);
    TestGraph.set_x_pass_pixel_per_frame(2);

    while (true) {
        while (SWWTool.get_start_state()) {
            SWWBrain.Screen.clearScreen();
            // write you GUI layout code here↓

            TestPanel.display();
            TestGraph.display();
            TestButtonGroup.display();
            TestSlider.display();

            // make sure everything render at the same time
            SWWBrain.Screen.render();
            // set the fps(fps setting could be seen in SWWTool.h)
            wait(SWWTool.get_frame_pause_time(), msec);
        }
        wait(SWWTool.get_frame_pause_time(), msec);
    }
}
