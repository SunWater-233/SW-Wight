#pragma once

#include "SWWight/SWWight.h"

namespace SWWight {
class graph {
   private:
    // basic variables inital
    // all color will be initialized in the constructor

    // basic variables of the graph
    int graph_base_point_x, graph_base_point_y;
    int graph_width, graph_height;
    int graph_line_width = 2;
    color graph_color;

    graph_line_style graph_style;

    /// @brief There is two display mode.
    /// STAY: All the data will remain in the graph, and zoom rate will change
    /// accroding to the data. PASS: There will only be some data in the graph,
    /// and the rest of data will be deleted.
    graph_display_mode graph_display;

    bool graph_remove_state = false;

    // data transfered from the user
    std::vector<float> x_raw_data;
    std::vector<float> y_raw_data;

    // The coordinate of dots on the Brain's screen
    std::vector<int> x_screen_pos;
    std::vector<int> y_screen_pos;

    float x_zoom_rate = 1.0;
    float y_zoom_rate = 1.0;
    int delta_space;
    int x_max, y_max;

    // only work in PASS mode
    // controll the lateral movement speed of the graph
    int x_pass_pixel_per_frame = 5;

    // basic variables of the axis
    int axis_width = 2;
    int axis_triangle_length = 10;
    float axis_triangle_angle = PI / 6;
    color axis_color;

    void draw_axis();

    /// @brief draw dots with specific width
    /// @param x unit is pixel
    /// @param y unit is pixel
    /// @param width unit is pixel
    void draw_dot_with_width(int x, int y, int width);

    /// @brief convert data to X coordinate values
    /// @param x_data
    /// @return X coordinate values
    int x_data_to_coordinate_system(float x_data);

    /// @brief convert data to Y coordinate values
    /// @param y_data
    /// @return Y coordinate values
    int y_data_to_coordinate_system(float y_data);

    /// @brief display data in the form of line
    void display_with_line();

    /// @brief display data in the form of dots
    void display_with_dot();

    graph* get_pointer_of_this_instance();

   public:
    /// @brief The constructor of Graph
    /// @param x x position(upper left corner)
    /// @param y y position(upper left corner)
    /// @param width the width of Slider
    /// @param height the height of Slider
    /// @param style the style pattern(LINE, DOT)
    /// @param mode the display mode(STAY, PASS)
    graph(int x, int y, int width, int height, graph_line_style style,
          graph_display_mode mode = STAY);

    /// @brief set origin coordinates
    /// @param x unit is pixel
    /// @param y unit is pixel
    void set_graph_base_point(int x, int y);

    /// @brief set the lateral movement speed of the graph
    /// @param space unit is pixel
    void set_x_pass_pixel_per_frame(int space);

    /// @brief set the size of the graph
    /// @param width unit is pixel
    /// @param height unit is pixel
    void set_graph_size(int width, int height);

    /// @brief set the color of line or dots in the graph
    /// @param hex_color require const char type
    void set_graph_color(const char *hex_color);

    /// @brief set the color of line or dots in the graph
    /// @param r
    /// @param g
    /// @param b
    void set_graph_color(int r, int g, int b);

    void set_graph_line_style(graph_line_style style);

    /// @brief set the color of line or dots in the axis
    /// @param hex_color require const char type
    void set_axis_color(const char *hex_color);

    /// @brief set the color of line or dots in the axis
    /// @param r
    /// @param g
    /// @param b
    void set_axis_color(int r, int g, int b);

    /// @brief whether this graph will be removed or not
    /// @return return true if this graph will be removed
    bool get_remove_state();

    /// @brief add data to the graph
    /// @param x
    /// @param y
    void add_data(float x, float y);

    /// @brief display the graph accronding to the line style and display mode
    void display();

    /// @brief clear all data in the graph
    void clear();

    /// @brief remove the graph from the render list(delte the graph)
    /// ATTENTION This function will REMOVE this instance from the MEMORY
    void remove();
};
}  // namespace SWWight
