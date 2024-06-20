#pragma once

#include <cstring>
#include <sstream>
#include <vector>

#include "vex.h"

#define PI 3.14159

enum interact_mode { PRESS, SELECT };
enum display_mode { STAY, PASS };

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
    float find_max_in_vec(std::vector<float> vec);

    /// @brief turn a float vaule into the type char* DONT forget to realse the memory
    /// @param value 
    /// @return a value in char* type
    char *float_to_char(float value);

    /// @brief turn a int vaule into the type char* DONT forget to realse the memory
    /// @param value 
    /// @return a value in char* type
    char *int_to_char(int value);
};
extern DevelopTool SWWTool;

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