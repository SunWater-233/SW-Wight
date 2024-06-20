#pragma once

#include "Button.h"
#include "SWWight/SWWTool.h"

class buttonGroup {
   private:
    // basic variables inital

    std::vector<button *> button_member;
    std::vector<int> selected_button_index;
    int selected_button_max = 1;

   public:
    buttonGroup(std::vector<button *> button_group, int selected_max = 1);

    /// @brief move every button in the group by the vaules you type
    /// @param delta_x the amount of pixels you want to move on the X direct
    /// @param delta_y the amount of pixels you want to move on the X direct
    void set_button_group_position(int delta_x, int delta_y);

    /// @brief change the color of every button in the group
    /// @param hex_color require const char type
    void set_button_group_color(const char *hex_color);

    /// @brief change the color of every button in the group
    /// @param r
    /// @param g
    /// @param b
    void set_button_group_color(int r, int g, int b);

    /// @brief change every button's outline width in the group
    /// @param width unit is pixel
    void set_button_group_outline_width(int width);

    /// @brief change every button's outline color in the group
    /// @param hex_color require const char type
    void set_button_group_outline_color(const char *hex_color);

    /// @brief change every button's outline color in the group
    /// @param r
    /// @param g
    /// @param b
    void set_button_group_outline_color(int r, int g, int b);

    /// @brief determine which button is being pressed
    /// @return return the index of the button, which is being pressed
    int determine_pressing_button();

    /// @brief determine which button is being selected
    /// @return return a vector made of the index of selected buttons
    std::vector<int> determine_selected_button();

    /// @brief show the button group
    void display();
};
