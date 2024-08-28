#include "SWWight/Widget/button.h"

using namespace SWWight;

/// --------------Button Class Functions--------------
button::button(int x, int y, int width, int hight,
               SWWight::button_interact_mode mode)
    : button_x(x),
      button_y(y),
      button_width(width),
      button_height(hight),
      button_interact(mode),
      ButtonPressDetector(button_x, button_y, button_x + button_width,
                          button_y + button_height)

{
    set_button_default_color(SWWColor.alizarin);
    set_button_selected_color(SWWColor.peter_river);
    set_outline_default_color(SWWColor.clouds);
    set_outline_selected_color(SWWColor.sun_flower);
    set_label_color(SWWColor.clouds);
}

button::button(int x, int y, int width, int hight, button_interact_mode mode,
               const char *hex_color)
    : button_x(x),
      button_y(y),
      button_width(width),
      button_height(hight),
      button_interact(mode),
      ButtonPressDetector(button_x, button_y, button_x + button_width,
                          button_y + button_height)

{
    set_button_default_color(hex_color);
    set_button_selected_color(SWWColor.peter_river);
    set_outline_default_color(SWWColor.clouds);
    set_outline_selected_color(SWWColor.sun_flower);
    set_label_color(SWWColor.clouds);
}

button::button(int x, int y, int width, int hight, button_interact_mode mode,
               int r, int g, int b)
    : button_x(x),
      button_y(y),
      button_width(width),
      button_height(hight),
      button_interact(mode),
      ButtonPressDetector(button_x, button_y, button_x + button_width,
                          button_y + button_height)

{
    set_button_default_color(r, g, b);
    set_button_selected_color(SWWColor.peter_river);
    set_outline_default_color(SWWColor.clouds);
    set_outline_selected_color(SWWColor.sun_flower);
    set_label_color(SWWColor.clouds);
}

void button::render_label() {
    SWWBrain.Screen.setPenColor(label_display_color);
    if (label_alignment == INSIDE) {
        SWWBrain.Screen.setFillColor(button_display_color);
    } else if (label_alignment == DOWNSIDE) {
        SWWBrain.Screen.setFillColor(transparent);
    }
    SWWBrain.Screen.setFont(label_display_font);
    SWWBrain.Screen.printAt(label_x, label_y, display_label_font);
}

void button::set_button_size(int width, int height) {
    button_width = width;
    button_height = height;

    ButtonPressDetector.set_x_detect_range(button_x, button_x + button_width);
    ButtonPressDetector.set_y_detect_range(button_y, button_y + button_height);
}

void button::set_button_position(int x, int y) {
    button_x = x;
    button_y = y;

    ButtonPressDetector.set_x_detect_range(button_x, button_x + button_width);
    ButtonPressDetector.set_y_detect_range(button_y, button_y + button_height);
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

void button::set_label_display_state(bool state) { display_label = state; }

void button::set_label(char *label, enum button_label_alignment alignment) {
    int label_width = SWWTool.get_character_width(label, label_display_font);
    int label_height = SWWTool.get_character_height(label, label_display_font);

    display_label = true;
    display_label_font = label;
    label_alignment = alignment;
    if (label_alignment == INSIDE) {
        float spare_space_width = (button_width - label_width) / 2;
        float spare_space_height = (button_height - label_height) / 2;

        label_x = button_x + spare_space_width;
        label_y = button_y + spare_space_height;
    }

    else if (label_alignment == DOWNSIDE) {
        float spare_space_width = (button_width - label_width) / 2;

        label_x = button_x + spare_space_width;
        label_y = button_y + button_height + 10;
    }
}

void button::set_label_color(const char *hex_color) {
    label_display_color.web(hex_color);
}

void button::set_label_color(int r, int g, int b) {
    label_display_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void button::set_label_font(fontType label_font) {
    label_display_font = label_font;
}

bool button::determine_selected() {
    if (button_interact == SELECT && determine_pressing()) {
        selected_state = !selected_state;
        waitUntil(!determine_pressing());
    }

    return selected_state;
}

bool button::determine_pressing() {
    if (ButtonPressDetector.area_pressing()) {
        pressing_state = true;
    } else {
        pressing_state = false;
    }
    return ButtonPressDetector.area_pressing();
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

    // draw the button
    // SWWBrain.Screen.setPenWidth(button_outline_width);
    // SWWBrain.Screen.setPenColor(outline_display_color);
    // SWWBrain.Screen.setFillColor(button_display_color);
    // SWWBrain.Screen.drawRectangle(button_x, button_y, button_width,
    //                               button_height);

    SWWGeometry.set_fill_color(button_display_color);
    SWWGeometry.set_outline_width(outline_display_color);
    SWWGeometry.draw_rectangle(button_x, button_y, button_width, button_height,
                               true);

    if (display_label) {
        render_label();
    }
}