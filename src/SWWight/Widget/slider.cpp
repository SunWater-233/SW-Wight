#include "SWWight/Widget/slider.h"

using namespace SWWight;

slider::slider(int x, int y, int width, int height, slider_layout_mode layout,
               float value_min, float value_max)
    : slider_x(x),
      slider_y(y),
      slider_width(width),
      slider_height(height),
      slider_layout(layout),
      slider_capacity_min(value_min),
      slider_capacity_max(value_max) {
    if (slider_layout == VERTICAL) {
        slider_dot_x = x + width / 2;
        slider_dot_y = y;
        slider_dot_radius = (width / 2) * slider_dot_zoom_rate;

        rectangle_x = x;
        rectangle_y = y - width / 2;
        rectangle_width = width;
        rectangle_height = height - width;

        rounded_corner_x = x + width / 2;
        rounded_corner_y = y - width / 2;
        rounded_corner_radius = width / 2;
    }

    else if (slider_layout == HORIZONTAL) {
        slider_dot_x = x;
        slider_dot_y = y + height / 2;
        slider_dot_radius = (height / 2) * slider_dot_zoom_rate;

        rectangle_x = x + height / 2;
        rectangle_y = y;
        rectangle_width = width - height;
        rectangle_height = height;

        rounded_corner_x = x + height / 2;
        rounded_corner_y = y + height / 2;
        rounded_corner_radius = height / 2;
    }

    set_fill_color(SWWColor.peter_river);
    set_outline_color(SWWColor.clouds);
    set_dot_color(SWWColor.carrot);

    set_outline_width(3);
}

bool slider::determine_slider_pressing() {
    if (!SWWBrain.Screen.pressing()) {
        return false;
    }

    int x_press = SWWBrain.Screen.xPosition();
    int y_press = SWWBrain.Screen.yPosition();
    bool x_condition =
        x_press >= slider_x && x_press <= slider_x + slider_width;
    bool y_condition =
        y_press >= slider_y && y_press <= slider_y + slider_height;

    return x_condition && y_condition;
}

void slider::update_dot_data() {
    if (!determine_slider_pressing()) {
        return;
    }
    int x_press = SWWBrain.Screen.xPosition();
    int y_press = SWWBrain.Screen.yPosition();

    if (slider_layout == VERTICAL) {
        slider_dot_y = y_press;
        value_proportionality = (slider_dot_y - slider_y) / slider_height;

    } else if (slider_layout == HORIZONTAL) {
        slider_dot_x = x_press;
        value_proportionality = (slider_dot_x - slider_x) / round(slider_width);
    }

    slider_current_value =
        value_proportionality * (slider_capacity_max - slider_capacity_min) +
        slider_capacity_min;
}

void slider::set_fill_color(const char *hex_color) {
    slider_fill_color.web(hex_color);
}

void slider::set_fill_color(int r, int g, int b) {
    slider_fill_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void slider::set_outline_width(int width) { slider_outline_width = width; }

void slider::set_outline_color(const char *hex_color) {
    slider_outline_color.web(hex_color);
}

void slider::set_outline_color(int r, int g, int b) {
    slider_outline_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void slider::set_dot_color(const char *hex_color) {
    slider_dot_color.web(hex_color);
}

void slider::set_dot_color(int r, int g, int b) {
    slider_dot_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void slider::set_slider_min_capacity(float min) { slider_capacity_min = min; }

void slider::set_slider_max_capacity(float max) { slider_capacity_max = max; }

float slider::get_slider_value() { return slider_current_value; }

void slider::display() {
    // draw the shape of the slider
    // draw the rounded corner
    SWWBrain.Screen.setPenWidth(slider_outline_width);
    SWWBrain.Screen.setPenColor(slider_outline_color);
    SWWBrain.Screen.setFillColor(slider_fill_color);

    // up/left side of rounded corners
    SWWBrain.Screen.drawCircle(rounded_corner_x, rounded_corner_y,
                               rounded_corner_radius);

    // down/right side of rounded corners
    if (slider_layout == VERTICAL) {
        SWWBrain.Screen.drawCircle(rounded_corner_x,
                                   rounded_corner_y + rectangle_height,
                                   rounded_corner_radius);
        SWWBrain.Screen.drawRectangle(rectangle_x, rectangle_y, rectangle_width,
                                      rectangle_height);

        SWWBrain.Screen.setPenColor(slider_fill_color);
        SWWBrain.Screen.setFillColor(slider_fill_color);
        SWWBrain.Screen.drawRectangle(
            rectangle_x + slider_outline_width,
            rectangle_y - slider_outline_width,
            rectangle_width - slider_outline_width * 2,
            rectangle_height + slider_outline_width * 2);
    }

    else if (slider_layout == HORIZONTAL) {
        SWWBrain.Screen.drawCircle(rounded_corner_x + rectangle_width,
                                   rounded_corner_y, rounded_corner_radius);
        SWWBrain.Screen.drawRectangle(rectangle_x, rectangle_y, rectangle_width,
                                      rectangle_height);

        SWWBrain.Screen.setPenColor(slider_fill_color);
        SWWBrain.Screen.setFillColor(slider_fill_color);
        SWWBrain.Screen.drawRectangle(
            rectangle_x - slider_outline_width,
            rectangle_y + slider_outline_width,
            rectangle_width + slider_outline_width,
            rectangle_height - slider_outline_width * 2);
    }

    // draw the dot of the slider
    update_dot_data();
    SWWBrain.Screen.setPenWidth(slider_outline_width);
    SWWBrain.Screen.setPenColor(slider_outline_color);
    SWWBrain.Screen.setFillColor(slider_dot_color);
    SWWBrain.Screen.drawCircle(slider_dot_x, slider_dot_y, slider_dot_radius);
}