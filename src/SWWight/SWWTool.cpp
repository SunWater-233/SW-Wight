#include "SWWight/SWWTool.h"

using namespace vex;

DevelopTool SWWTool;
SWWHexColor SWWColor;

color DevelopTool::rgb_to_vex_color(int r, int g, int b) {
    color tmp = color(r, g, b);
    return tmp;
}

void DevelopTool::set_start_state(bool state) { start_gui = state; }

bool DevelopTool::get_start_state() { return start_gui; }

float DevelopTool::get_frame_pause_time() { return frame_pause_time; }

int DevelopTool::get_character_width(char *str, fontType font) {
    int font_width;

    Brain.Screen.setFont(font);
    font_width = Brain.Screen.getStringWidth(str);

    return font_width;
}

int DevelopTool::get_character_height(char* str, fontType font) {
    int font_height;

    Brain.Screen.setFont(font);
    font_height = Brain.Screen.getStringHeight(str);

    return font_height;
}

float DevelopTool::find_max_in_vec(std::vector<float> vec) {
    float max = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }
    return max;
}

char* DevelopTool::float_to_char(float value) {
    std::ostringstream oss;
    oss << value;
    std::string str = oss.str();
    char* result = new char[str.length() + 1];
    std::strcpy(result, str.c_str());

    return result;
}

char* DevelopTool::int_to_char(int value) {
    std::ostringstream oss;
    oss << value;
    std::string str = oss.str();
    char* result = new char[str.length() + 1];
    std::strcpy(result, str.c_str());

    return result;
}