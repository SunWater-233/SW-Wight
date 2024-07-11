#pragma once

#include "SWWight/SWWTool.h"

namespace SWWight {
class slider {
   private:
    int slider_x, slider_y;
    int slider_width, slider_height;
    slider_layout_mode slider_layout = HORIZONTAL;
    color slider_fill_color;
    color slider_empty_color;

    int slider_outline_width = 5;
    color slider_outline_color;

    int slider_dot_x, slider_dot_y;
    int slider_dot_radius;
    color slider_dot_color;

    // define the max and min value that the slider can hold
    float slider_capacity_min = 0;
    float slider_capacity_max = 100;

    // some variables used during diaplay prograss
    int rectangle_x, rectangle_y;
    int rectangle_width, rectangle_height;
    int rounded_corner_x, rounded_corner_y;
    int rounded_corner_radius;

    bool determine_slider_pressing();
    void update_dot_position();

   public:
    slider(int x, int y, int width, int height, slider_layout_mode layout,
           float value_min, float value_max);

    /// @brief set the fill color of the slider
    /// @param hex_color require const char type
    void set_fill_color(const char *hex_color);

    /// @brief set the fill color of the slider
    /// @param r
    /// @param g
    /// @param b
    void set_fill_color(int r, int g, int b);

    /// @brief set the empty color of the slider
    /// @param hex_color require const char type
    void set_empty_color(const char *hex_color);

    /// @brief set the empty color of the slider
    /// @param r
    /// @param g
    /// @param b
    void set_empty_color(int r, int g, int b);

    /// @brief set the outline's width of the slider
    /// @param width unit is pixel
    void set_outline_width(int width);

    /// @brief set the outline color of the slider
    /// @param hex_color require const char type
    void set_outline_color(const char *hex_color);

    /// @brief set the outline color of the slider
    /// @param r
    /// @param g
    /// @param b
    void set_outline_color(int r, int g, int b);

    /// @brief set the dot color of the slider
    /// @param hex_color require const char type
    void set_dot_color(const char *hex_color);

    /// @brief set the dot color of the slider
    /// @param r
    /// @param g
    /// @param b
    void set_dot_color(int r, int g, int b);

    /// @brief set the minimum value the slider can give
    /// @param min float type
    void set_slider_min_capacity(float min);

    /// @brief set the maximum value the slider can give
    /// @param min float type
    void set_slider_max_capacity(float max);

    /// @brief get the current vaule of the slider
    /// @return current vaule of the slider.float type
    float get_slider_value();

    /// @brief display the slider
    void display();
};

}  // namespace SWWight