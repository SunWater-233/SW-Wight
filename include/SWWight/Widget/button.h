#pragma once

#include "SWWight/SWWTool.h"

namespace SWWight {
class button{
   private:
    // basic variables inital
    // all color will be initialized in the constructor

    int button_x, button_y;
    int button_width, button_height;
    color button_default_color;
    color button_selected_color;
    color button_display_color;

    int button_outline_width = 3;
    color outline_display_color;
    color outline_default_color;
    color outline_selected_color;
    bool pressing_state = false;
    bool selected_state = false;

    /// @brief There are to interact modes.
    /// PRESS: The button can be pressed.
    /// SELECT: The button can be selected.
    enum SWWight::button_interact_mode button_interact;

   public:
    // constructors for the button
    button(int x, int y, int width, int hight, SWWight::button_interact_mode mode);
    button(int x, int y, int width, int hight, button_interact_mode mode,
           const char *hex_color);
    button(int x, int y, int width, int hight, button_interact_mode mode, int r, int g,
           int b);

    /// @brief set the size of button
    /// @param width  unit is pixel
    /// @param height  unit is pixel
    void set_button_size(int width, int height);

    /// @brief set the position of button
    /// @param x unit is pixel
    /// @param y unit is pixel
    void set_button_position(int x, int y);

    /// @brief set the color of the button when the button isn't pressed or
    /// selecteed
    /// @param hex_color require const char type
    void set_button_default_color(const char *hex_color);

    /// @brief set the color of the button when the button isn't pressed or
    /// selecteed
    /// @param r
    /// @param g
    /// @param b
    void set_button_default_color(int r, int g, int b);

    /// @brief set the color of the button when the button is selecteed
    /// @param hex_color require const char type
    void set_button_selected_color(const char *hex_color);

    /// @brief set the color of the button when the button is selecteed
    /// @param r
    /// @param g
    /// @param b
    void set_button_selected_color(int r, int g, int b);

    /// @brief set the outline's width of the button
    /// @param width unit is pixel
    void set_outline_width(int width);

    /// @brief set the color of the outline  when the button is isn't pressed or
    /// selecteed
    /// @param hex_color require const char type
    void set_outline_default_color(const char *hex_color);

    /// @brief set the color of the outline  when the button is isn't pressed or
    /// selecteed
    /// @param r
    /// @param g
    /// @param b
    void set_outline_default_color(int r, int g, int b);

    /// @brief set the color of the outline when the button is selecteed
    /// @param hex_color require const char type
    void set_outline_selected_color(const char *hex_color);

    /// @brief set the color of the outline when the button is selecteed
    /// @param r
    /// @param g
    /// @param b
    void set_outline_selected_color(int r, int g, int b);

    /// @brief set button's reaction towards user's movement
    /// @param mode button_interact_mode include PRESS and SELECTED
    void set_interact_state(enum button_interact_mode mode);

    /// @brief set the button select state
    /// @param state
    void set_select_state(bool state);

    /// @brief check whether the button is selected or no
    /// @return return true if the button is selected.If not, return false
    bool determine_selected();

    /// @brief check whether the button is being pressed or no
    /// @return return true if the button is selected.If not, return false
    bool determine_pressing();

    /// @brief transfer the button's select state
    /// @return return true if the button is selected.If not, return false
    bool get_selected_state();

    /// @brief transfer the button's abscissa
    /// @return the button's abscissa
    int get_x_position();

    /// @brief transfer the button's ordinate
    /// @return the button's ordinate
    int get_y_position();

    /// @brief transfer the button's interact mode
    /// @return the button's interact mode
    button_interact_mode get_interact_mode();

    /// @brief show the button
    void display();
};

}  // namespace SWWight
