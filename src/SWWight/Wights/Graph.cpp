#include "SWWight/Wight/Graph.h"

using namespace vex;

graph::graph(int x, int y, int width, int height, display_mode mode)
    : graph_base_point_x(x),
      graph_base_point_y(y),
      graph_width(width),
      graph_height(height),
      graph_display_mode(mode)

{
    x_screen_pos = {x};
    y_screen_pos = {y};

    set_graph_color(SWWColor.clouds);
    set_axis_color(SWWColor.clouds);
}

void graph::draw_axis() {
    int triangle_height = axis_triangle_length * sin(axis_triangle_angle);
    int triangle_width = axis_triangle_length * cos(axis_triangle_angle);

    Brain.Screen.setPenColor(axis_color);
    Brain.Screen.setPenWidth(axis_width);

    // draw X triangle
    Brain.Screen.drawLine(graph_base_point_x + graph_width, graph_base_point_y,
                          graph_base_point_x + graph_width - triangle_width,
                          graph_base_point_y + triangle_height);
    Brain.Screen.drawLine(graph_base_point_x + graph_width, graph_base_point_y,
                          graph_base_point_x + graph_width - triangle_width,
                          graph_base_point_y - triangle_height);

    // draw Y triangle
    Brain.Screen.drawLine(graph_base_point_x, graph_base_point_y - graph_height,
                          graph_base_point_x - triangle_height,
                          graph_base_point_y - graph_height + triangle_width);
    Brain.Screen.drawLine(graph_base_point_x, graph_base_point_y - graph_height,
                          graph_base_point_x + triangle_height,
                          graph_base_point_y - graph_height + triangle_width);

    // draw the X asis
    Brain.Screen.drawLine(graph_base_point_x, graph_base_point_y,
                          graph_base_point_x + graph_width, graph_base_point_y);

    // draw the Y asis
    Brain.Screen.drawLine(graph_base_point_x, graph_base_point_y,
                          graph_base_point_x,
                          graph_base_point_y - graph_height);
}

void graph::draw_dot_with_width(int x, int y, int width) {
    int dot_width = sqrt(width);
    Brain.Screen.drawRectangle(x, y, dot_width, dot_width);
}

int graph::x_data_to_coordinate_system(float x_data) {
    int x_out = graph_base_point_x + graph_width;

    if (graph_display_mode == STAY) {
        float x_max = SWWTool.find_max_in_vec(x_raw_data);
        if (x_max != 0) {
            x_zoom_rate = graph_width / x_max;
            x_out = x_data * x_zoom_rate + graph_base_point_x;
        } else {
            x_out = graph_base_point_x;
        }

    } else if (graph_display_mode == PASS) {
        if (x_raw_data.size() >= 3) {
            x_zoom_rate = x_pass_space_per_frame / fabs(x_raw_data[x_raw_data.size() - 4] -
                                         x_raw_data[x_raw_data.size() - 3]);
            delta_space = x_zoom_rate * fabs(x_raw_data[x_raw_data.size() - 2] -
                                             x_raw_data[x_raw_data.size() - 1]);
        } else {
            delta_space = x_pass_space_per_frame;
        }
    }

    return x_out;
}

int graph::y_data_to_coordinate_system(float y_data) {
    float y_max = SWWTool.find_max_in_vec(y_raw_data);
    if (y_max != 0) {
        y_zoom_rate = graph_height / y_max;
        return graph_base_point_y - y_data * y_zoom_rate;
    }
    return graph_base_point_y;
}

void graph::set_graph_base_point(int x, int y) {
    graph_base_point_x = x;
    graph_base_point_y = y;
}

void graph::set_x_pass_space_per_frame(int space) { x_pass_space_per_frame = space; }

void graph::set_graph_width(int width) { graph_line_width = width; }

void graph::set_graph_color(const char *hex_color) {
    graph_color.web(hex_color);
}

void graph::set_graph_color(int r, int g, int b) {
    graph_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void graph::set_axis_color(const char *hex_color) { axis_color.web(hex_color); }

void graph::set_axis_color(int r, int g, int b) {
    axis_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void graph::add_data(float x, float y) {
    std::vector<int> x_output;
    std::vector<int> y_output;
    int x_pos = graph_base_point_x;
    int y_pos = graph_base_point_y;

    x_raw_data.push_back(x);
    if (y >= 0) {
        y_raw_data.push_back(y);
    } else {
        y_raw_data.push_back(0);
    }

    for (int i = 0; i < x_raw_data.size(); i++) {
        x_pos = x_data_to_coordinate_system(x_raw_data[i]);
        y_pos = y_data_to_coordinate_system(y_raw_data[i]);

        x_output.push_back(x_pos);
        y_output.push_back(y_pos);

        if (graph_display_mode == PASS) {
            for (int j = 0; j < x_output.size() - 1; j++) {
                x_output[j] -= delta_space;
                if (x_output[j] < graph_base_point_x) {
                    x_output.erase(x_output.begin() + j);
                    y_output.erase(y_output.begin() + j);

                    x_raw_data.erase(x_raw_data.begin() + j);
                    y_raw_data.erase(y_raw_data.begin() + j);
                }
            }
        }
    }

    x_screen_pos = x_output;
    y_screen_pos = y_output;
}

void graph::clear() {
    x_screen_pos = {};
    y_screen_pos = {};
    x_raw_data = {};
    y_raw_data = {};

    x_zoom_rate = 1.0;
    y_zoom_rate = 1.0;
}

void graph::draw_line() {
    draw_axis();
    Brain.Screen.setPenColor(graph_color);
    Brain.Screen.setPenWidth(graph_line_width);

    for (int i = 1; i < x_screen_pos.size(); i++) {
        Brain.Screen.drawLine(x_screen_pos[i - 1], y_screen_pos[i - 1],
                              x_screen_pos[i], y_screen_pos[i]);
    }
}

void graph::draw_dot() {
    draw_axis();
    Brain.Screen.setPenColor(graph_color);
    Brain.Screen.setFillColor(graph_color);
    for (int i = 1; i < x_screen_pos.size(); i++) {
        draw_dot_with_width(x_screen_pos[i], y_screen_pos[i], graph_line_width);
    }
}
