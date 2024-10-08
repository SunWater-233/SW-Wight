#pragma once

#include "SWWight/SWWTool.h"

namespace SWWight {
class panel {
   private:
    // basic variables inital
    // all color will be initialized in the constructor

    int panel_x_position, panel_y_position;
    color panel_backgroud_color;

    int chart_radius;
    int chart_center_x;
    int chart_center_y;

    float data_lim_min, data_lim_max;
    int panel_data = 0;
    float indicator_angle = 0;

    char *data_label;
    int data_label_x;
    int data_label_y;
    int data_label_width;
    int data_label_height;
    bool data_label_render = true;
    color data_label_color;
    fontType data_label_font = fontType::mono40;

    int outline_width = 3;
    color outline_color;

    int indicator_width = 5;
    color indicator_color;

    void set_data_label_width_height();

   public:
    /// @brief The constructor of Panel
    /// @param x x position(upper left corner)
    /// @param y y position(upper left corner)
    /// @param radius the radius of the panel
    /// @param data_lim_min the minimum value the panel should receive
    /// @param data_lim_max the maximum value the panel should receive
    panel(int x, int y, int radius, float data_lim_min, float data_lim_max);

    /// @brief set the position of the panel
    /// @param x unit is pixel
    /// @param y unit is pixel
    void set_panel_position(int x, int y);

    /// @brief set the radius of the panel
    /// @param radius unit is pixel
    void set_panel_radius(int radius);

    /// @brief transfer the data into the
    /// @param data
    void set_panel_data(int data);

    /// @brief set the minimum vaule of the data
    /// @param min_lim
    void set_panel_data_min(float min_lim);

    // @brief set the maximum  vaule of the data
    /// @param min_lim
    void set_panel_data_max(float max_lim);

    /// @brief whether the data label be rendered
    /// @param state
    void set_data_label_enable(bool state);

    /// @brief set labe color
    /// @param hex_color require const char type
    void set_data_label_color(const char *hex_color);

    /// @brief set labe color
    /// @param r
    /// @param g
    /// @param b
    void set_data_label_color(int r, int g, int b);

    /// @brief set label font
    /// @param font
    void set_data_label_font(fontType font);

    /// @brief set outline width
    /// @param width unit is pixel
    void set_ouline_width(int width);

    /// @brief set outline color
    /// @param hex_color require const char type
    void set_outline_color(const char *hex_color);

    /// @brief set outline color
    /// @param r
    /// @param g
    /// @param b
    void set_outline_color(int r, int g, int b);

    /// @brief the indicator is the pionter on the panel
    /// @param hex_color require const char type
    void set_indicator_color(const char *hex_color);

    /// @brief the indicator is the pionter on the panel
    /// @param r
    /// @param g
    /// @param b
    void set_indicator_color(int r, int g, int b);

    /// @brief set the background of the panel
    /// @param hex_color
    void set_backgroud_color(const char *hex_color);

    /// @brief set the background of the panel
    /// @param r
    /// @param g
    /// @param b
    void set_backgroud_color(int r, int g, int b);

    /// @brief Attention! This function might change your font
    /// setting on Screen.Remember to RESET your font if you need it.
    void display();
};
}  // namespace SWWight
