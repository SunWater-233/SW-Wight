#include "SWWight/Widget/panel.h"

using namespace SWWight;

panel::panel(int x, int y, int radius, float data_lim_min, float data_lim_max)
    : panel_x_position(x),
      panel_y_position(y),

      chart_radius(radius),
      chart_center_x(panel_x_position + chart_radius),
      chart_center_y(panel_y_position + chart_radius),

      data_lim_min(data_lim_min),
      data_lim_max(data_lim_max)

{
    set_data_label_color(SWWColor.sun_flower);
    set_outline_color(SWWColor.clouds);
    set_indicator_color(SWWColor.clouds);
    set_backgroud_color(SWWColor.midnight_blue);
}

void panel::set_data_label_width_height() {
    data_label_width = SWWTool.get_character_width(data_label, data_label_font);
    data_label_height =
        SWWTool.get_character_height(data_label, data_label_font);
}

void panel::set_panel_position(int x, int y) {
    panel_x_position = x;
    panel_y_position = y;

    chart_center_x = panel_x_position + chart_radius;
    chart_center_y = panel_y_position + chart_radius;
}

void panel::set_panel_radius(int radius) {
    chart_radius = radius;
    chart_center_x = panel_x_position + chart_radius;
    chart_center_y = panel_y_position + chart_radius;
}

void panel::set_panel_data(int data) {
    panel_data = data;
    indicator_angle = data / fabs(data_lim_max - data_lim_min) * 2 * M_PI;
}

void panel::set_panel_data_min(float min_lim) { data_lim_min = min_lim; }

void panel::set_panel_data_max(float max_lim) { data_lim_max = max_lim; }

void panel::set_data_label_color(const char *hex_color) {
    data_label_color.web(hex_color);
}

void panel::set_data_label_enable(bool state) { data_label_render = state; }

void panel::set_data_label_color(int r, int g, int b) {
    data_label_color = SWWTool.rgb_to_vex_color(r, g, b);
}
void panel::set_data_label_font(fontType font) { data_label_font = font; }

void panel::set_ouline_width(int width) { outline_width = width; }

void panel::set_outline_color(const char *hex_color) {
    outline_color.web(hex_color);
}

void panel::set_outline_color(int r, int g, int b) {
    outline_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void panel::set_indicator_color(const char *hex_color) {
    indicator_color.web(hex_color);
}

void panel::set_indicator_color(int r, int g, int b) {
    indicator_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void panel::set_backgroud_color(const char *hex_color) {
    panel_backgroud_color.web(hex_color);
}

void panel::set_backgroud_color(int r, int g, int b) {
    panel_backgroud_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void panel::display() {
    int indicator_end_x_pos =
        chart_center_x - (chart_radius - outline_width) * cos(indicator_angle);
    ;
    int indicator_end_y_pos =
        chart_center_y - (chart_radius - outline_width) * sin(indicator_angle);

    // draw panel's shape
    SWWBrain.Screen.setPenWidth(outline_width);
    SWWBrain.Screen.setPenColor(outline_color);
    SWWBrain.Screen.setFillColor(panel_backgroud_color);
    SWWBrain.Screen.drawCircle(chart_center_x, chart_center_y, chart_radius);

    // draw the data label
    if (data_label_render) {
        data_label = SWWTool.int_to_char(panel_data);
        SWWBrain.Screen.setPenColor(data_label_color);
        SWWBrain.Screen.setFillColor(panel_backgroud_color);
        SWWBrain.Screen.setFont(data_label_font);
        set_data_label_width_height();

        data_label_x = chart_center_x - data_label_width / 2;
        data_label_y =
            chart_center_y + data_label_height / 2 + chart_radius / 2;

        SWWBrain.Screen.printAt(data_label_x, data_label_y, data_label);
        delete[] data_label;  // release memory of data_label
        
    // draw the indicator
    SWWBrain.Screen.setPenColor(indicator_color);
    SWWBrain.Screen.setPenWidth(indicator_width);
    SWWBrain.Screen.drawLine(chart_center_x, chart_center_y,
                             indicator_end_x_pos, indicator_end_y_pos);
    }
}