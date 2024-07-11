#include "SWWight/Widget/button.h"

using namespace SWWight;

/// --------------Button Class Functions--------------
button::button(int x, int y, int width, int hight,
               SWWight::button_interact_mode mode)
    : button_x(x),
      button_y(y),
      button_width(width),
      button_height(hight),
      button_interact(mode) {
    set_button_default_color(SWWColor.alizarin);
    set_button_selected_color(SWWColor.peter_river);
    set_outline_default_color(SWWColor.clouds);
    set_outline_selected_color(SWWColor.sun_flower);
}

button::button(int x, int y, int width, int hight, button_interact_mode mode,
               const char *hex_color)
    : button_x(x),
      button_y(y),
      button_width(width),
      button_height(hight),
      button_interact(mode)

{
    set_button_default_color(hex_color);
    set_button_selected_color(SWWColor.peter_river);
    set_outline_default_color(SWWColor.clouds);
    set_outline_selected_color(SWWColor.sun_flower);
}

button::button(int x, int y, int width, int hight, button_interact_mode mode,
               int r, int g, int b)
    : button_x(x),
      button_y(y),
      button_width(width),
      button_height(hight),
      button_interact(mode) {
    set_button_default_color(r, g, b);
    set_button_selected_color(SWWColor.peter_river);
    set_outline_default_color(SWWColor.clouds);
    set_outline_selected_color(SWWColor.sun_flower);
}

void button::set_button_size(int width, int height) {
    button_width = width;
    button_height = height;
}

void button::set_button_position(int x, int y) {
    button_x = x;
    button_y = y;
}

void button::set_button_default_color(const char *hex_color) {
    button_default_color.web(hex_color);
}

void button::set_button_default_color(int r, int g, int b) {
    button_default_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void button::set_button_selected_color(const char *hex_color) {
    button_selected_color.web(hex_color);
}

void button::set_button_selected_color(int r, int g, int b) {
    button_selected_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void button::set_outline_width(int width) { button_outline_width = width; }

void button::set_outline_default_color(const char *hex_color) {
    outline_default_color.web(hex_color);
}

void button::set_outline_default_color(int r, int g, int b) {
    outline_default_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void button::set_outline_selected_color(const char *hex_color) {
    outline_selected_color.web(hex_color);
}

void button::set_outline_selected_color(int r, int g, int b) {
    outline_selected_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void button::set_interact_state(enum button_interact_mode mode) {
    button_interact = mode;
}

void button::set_select_state(bool state) { selected_state = state; }

bool button::determine_selected() {
    if (button_interact == SELECT && determine_pressing()) {
        selected_state = !selected_state;
        waitUntil(!determine_pressing());
    }

    return selected_state;
}

bool button::determine_pressing() {
    if (!Brain.Screen.pressing()) {
        pressing_state = false;
        return false;
    }

    int x_press = Brain.Screen.xPosition();
    int y_press = Brain.Screen.yPosition();
    bool x_condition =
        x_press >= button_x && x_press <= button_x + button_width;
    bool y_condition =
        y_press >= button_y && y_press <= button_y + button_height;

    pressing_state = x_condition && y_condition;
    return pressing_state;
}

bool button::get_selected_state() { return selected_state; }

int button::get_x_position() { return button_x; }

int button::get_y_position() { return button_y; }

button_interact_mode button::get_interact_mode() { return button_interact; }

void button::display() {
    if (selected_state || pressing_state) {
        button_display_color = button_selected_color;
        outline_display_color = outline_selected_color;
    } else {
        button_display_color = button_default_color;
        outline_display_color = outline_default_color;
    }

    // draw outline
    SWWBrain.Screen.setPenColor(outline_display_color);
    SWWBrain.Screen.setFillColor(outline_display_color);
    SWWBrain.Screen.drawRectangle(button_x, button_y, button_width,
                                  button_height);

    // draw button
    SWWBrain.Screen.setPenColor(button_display_color);
    SWWBrain.Screen.setFillColor(button_display_color);
    SWWBrain.Screen.drawRectangle(button_x + button_outline_width,
                                  button_y + button_outline_width,
                                  button_width - 2 * button_outline_width,
                                  button_height - 2 * button_outline_width);
}
