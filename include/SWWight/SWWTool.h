#pragma once

#include <array>
#include <cstring>
#include <sstream>
#include <vector>

#include "vex.h"

namespace SWWight {

#define PI 3.14159

extern vex::brain SWWBrain;

/// @brief There are two interact modes for Button
/// PRESS: The button can be pressed
/// SELECT: The button can selected
enum button_interact_mode { PRESS, SELECT };

/// @brief There is two display modes for Graph
/// STAY: All the data will remain in the graph, and zoom rate will change
/// accroding to the data. PASS: There will only be some data in the graph, and
/// the rest of data will be deleted.
enum graph_display_mode { STAY, PASS };

/// @brief There are two line styles
/// LINE: The graph's data will be presented as a line
/// DOT: The graph's data will be presented as dots
enum graph_line_style { LINE, DOT };

/// @brief There are two layout mode for Slider
/// VERTICAL: The slider will be placed vertically
/// HORIZONTAL: The slider will be placed horizontally
enum slider_layout_mode { VERTICAL, HORIZONTAL };

class DevelopTool {
   private:
    // basic variables inital

    bool start_gui = true;  // whether start to display wights or not
    float fps = 60;
    float frame_pause_time = 1000 / fps;  // unit is msec

    int screen_width = 480;
    int screen_height = 240;

   public:
    /// @brief turn the rgb color into the color type that vex recognize
    /// @param r
    /// @param g
    /// @param b
    /// @return color type
    color rgb_to_vex_color(int r, int g, int b);

    /// @brief set whether to start to display wights or not
    /// @param state
    void set_start_state(bool state);

    /// @brief transfer start state
    /// @return start state
    bool get_start_state();

    /// @brief transfer the time value needed to stop between frames
    /// @return a time value needed to stop between frames
    float get_frame_pause_time();

    /// @brief Attention! This function might change your font
    /// setting on Screen.Remember to RESET your font if you need it.
    /// @param str
    /// @param font
    /// @return return the width of the string based on your font
    int get_character_width(char *str, fontType font);

    /// @brief Attention! This function might change your font
    /// setting on Screen.Remember to RESET your font if you need it.
    /// @param str
    /// @param font
    /// @return return the heiight of the string based on your font
    int get_character_height(char *str, fontType font);

    /// @brief find the largest element in a float vector.
    /// @param vec a float vector
    /// @return the value of the largest element
    float find_max_in_float_vec(std::vector<float> vec);

    /// @brief find specfic element in a vector
    /// @param vec
    /// @return the index of the found element.If finds nothing, return -1
    template <typename T>
    int get_element_index_in_vec(std::vector<T> vec, T to_find);

    /// @brief turn a float vaule into the type char* DONT forget to realse the
    /// memory
    /// @param value
    /// @return a value in char* type
    char *float_to_char(float value);

    /// @brief turn a int vaule into the type char* DONT forget to realse the
    /// memory
    /// @param value
    /// @return a value in char* type
    char *int_to_char(int value);

    class PressDetector {
       private:
        int x_detect_range[2] = {0, 0};
        int y_detect_range[2] = {0, 0};

        int x_press_postion = -1;
        int y_press_postion = -1;

       public:
        PressDetector(int x1, int y1, int x2, int y2);
        void set_x_detect_range(int x1, int x2);
        void set_y_detect_range(int y1, int y2);

        bool area_pressing();
        std::array<int, 2> get_press_position();
    };
};

extern DevelopTool SWWTool;

// color below is from https://flatuicolors.com/palette/defo
class SWWHexColor {
   public:
    const char *peter_river = "#3498db";
    const char *belize_hole = "#2980b9";
    const char *amethyst = "#9b59b6";
    const char *wisteria = "#8e44ad";
    const char *wet_asphalt = "#34495e";
    const char *midnight_blue = "#2c3e50";
    const char *turquoise = "#1abc9c";
    const char *green_tea = "#16a085";
    const char *sun_flower = "#f1c40f";
    const char *emerald = "#2ecc71";
    const char *nephritis = "#27ae60";
    const char *orange = "#f39c12";
    const char *carrot = "#e67e22";
    const char *pumpkin = "#d35400";
    const char *alizarin = "#e74c3c";
    const char *pomegranate = "#c0392b";
    const char *clouds = "#ecf0f1";
    const char *silver = "#bdc3c7";
    const char *concrete = "#95a5a6";
    const char *asbestos = "#7f8c8d";
};
extern SWWHexColor SWWColor;

}  // namespace SWWight
