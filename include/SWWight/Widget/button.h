#pragma once

#include "SWWight/SWWTool.h"

namespace SWWight {
class button {
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

    int label_x, label_y;
    bool display_label = false;
    char *display_label_font = "";
    enum button_label_alignment label_alignment = INSIDE;
    color label_display_color;
    fontType label_display_font = mono20;

    /// @brief There are interact modes.
    /// PRESS: The button can be pressed.
    /// SELECT: The button can be selected.
    enum button_interact_mode button_interact;

    DevelopTool::PressDetector ButtonPressDetector;
    bool pressing_state = false;
    bool selected_state = false;

    /// @brief display the label
    void render_label();

   public:
    // constructors for the button

    /// @brief The constructor of Button
    /// @param x x position(upper left corner)
    /// @param y y position(upper left corner)
    /// @param width the width of Button
    /// @param hight the height of Button
    /// @param mode  the interact mode of button(PRESS, SELECT)
    button(int x, int y, int width, int hight,
           SWWight::button_interact_mode mode);

    /// @brief The constructor of Button
    /// @param x x position(upper left corner)
    /// @param y y position(upper left corner)
    /// @param width the width of Button
    /// @param hight the height of Button
    /// @param mode  the interact mode of button(PRESS, SELECT)
    button(int x, int y, int width, int hight, button_interact_mode mode,
           const char *hex_color);

    /// @brief The constructor of Button
    /// @param x x position(upper left corner)
    /// @param y y position(upper left corner)
    /// @param width the width of Button
    /// @param hight the height of Button
    /// @param mode the interact mode of button(PRESS, SELECT)
    button(int x, int y, int width, int hight, button_interact_mode mode, int r,
           int g, int b);

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

    /// @brief whether to display label or not
    /// @param state
    void set_label_display_state(bool state);

    /// @brief set what to print as a label
    /// @param label
    /// @param alignment where you want to display the label
    void set_label(char *label, enum button_label_alignment alignment = INSIDE);

    /// @brief set the color of the outline  when the button is isn't pressed or
    /// selecteed
    /// @param hex_color require const char type
    void set_label_color(const char *hex_color);

    /// @brief set the color of the outline  when the button is isn't pressed or
    /// selecteed
    /// @param r
    /// @param g
    /// @param b
    void set_label_color(int r, int g, int b);

    void set_label_font(fontType label_font);

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