#include "SWWight/SWWTool.h"

// some definations of classes in the namespace
namespace SWWight {
vex::brain SWWBrain;
DevelopTool SWWTool;
DrawGeometry SWWGeometry;
SWWHexColor SWWColor;
}  // namespace SWWight

using namespace SWWight;

color DevelopTool::rgb_to_vex_color(int r, int g, int b) {
    color tmp = color(r, g, b);
    return tmp;
}

void DevelopTool::set_start_state(bool state) { start_gui = state; }

bool DevelopTool::get_start_state() { return start_gui; }

float DevelopTool::get_frame_pause_time() { return frame_pause_time; }

int DevelopTool::get_character_width(char* str, fontType font) {
    int font_width;

    SWWBrain.Screen.setFont(font);
    font_width = SWWBrain.Screen.getStringWidth(str);

    return font_width;
}

int DevelopTool::get_character_height(char* str, fontType font) {
    int font_height;

    SWWBrain.Screen.setFont(font);
    font_height = SWWBrain.Screen.getStringHeight(str);

    return font_height;
}

template <typename T>
int DevelopTool::get_element_index_in_vec(std::vector<T> vec, T to_find) {
    int index = -1;
    auto it = std::find(vec.begin(), vec.end(), to_find);

    if (vec.empty() || it == vec.end()) {
        index = -1;
    } else {
        index = std::distance(vec.begin(), it);
    }

    return index;
}

float DevelopTool::find_max_in_float_vec(std::vector<float> vec) {
    float max = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }
    return max;
}

char* DevelopTool::float_to_char(float value) {
    std::ostringstream oss;
    oss << value;
    std::string str = oss.str();
    char* result = new char[str.length() + 1];
    std::strcpy(result, str.c_str());

    return result;
}

char* DevelopTool::int_to_char(int value) {
    std::ostringstream oss;
    oss << value;
    std::string str = oss.str();
    char* result = new char[str.length() + 1];
    std::strcpy(result, str.c_str());

    return result;
}

DevelopTool::PressDetector::PressDetector(int x1, int y1, int x2, int y2) {
    x_detect_range[0] = x1;
    x_detect_range[1] = x2;

    y_detect_range[0] = y1;
    y_detect_range[1] = y2;
}

void DevelopTool::PressDetector::set_x_detect_range(int x1, int x2) {
    x_detect_range[0] = x1;
    x_detect_range[1] = x2;
}

void DevelopTool::PressDetector::set_y_detect_range(int y1, int y2) {
    y_detect_range[0] = y1;
    y_detect_range[1] = y2;
}

bool DevelopTool::PressDetector::area_pressing() {
    if (!SWWBrain.Screen.pressing()) {
        return false;
    }

    x_press_postion = SWWBrain.Screen.xPosition();
    y_press_postion = SWWBrain.Screen.yPosition();

    bool x_condition = x_press_postion >= x_detect_range[0] &&
                       x_press_postion <= x_detect_range[1];
    bool y_condition = y_press_postion >= y_detect_range[0] &&
                       y_press_postion <= y_detect_range[1];

    return x_condition && y_condition;
}

std::array<int, 2> DevelopTool::PressDetector::get_press_position() {
    if (!area_pressing()) {
        return {-1, -1};
    }

    return {x_press_postion, y_press_postion};
}

DrawGeometry::DrawGeometry() {
    fill_color.web(SWWColor.midnight_blue);
    outline_color.web(SWWColor.clouds);
}

std::array<float, 2> DrawGeometry::rotate_coordinate(float origin_x,
                                                     float origin_y, float x,
                                                     float y,
                                                     float rotation_angle) {
    // 将角度转换为弧度
    float radian = rotation_angle * M_PI / 180.0;

    // 平移点，使旋转中心变为原点
    float x_prime = x - origin_x;
    float y_prime = y - origin_y;

    // 旋转点
    float x_rotated = x_prime * cos(radian) - y_prime * sin(radian);
    float y_rotated = x_prime * sin(radian) + y_prime * cos(radian);

    // 平移回原始坐标系
    float x_final = x_rotated + origin_x;
    float y_final = y_rotated + origin_y;

    return {x_final, y_final};
}

std::array<float, 2> DrawGeometry::rotate_coordinate(float x, float y,
                                                     float rotation_angle) {
    return rotate_coordinate(0, 0, x, y, rotation_angle);
}

std::array<float, 2> DrawGeometry::move_coordinate(float delta_x, float delta_y,
                                                   std::array<float, 2> dot) {
    return {dot[0] + delta_x, dot[1] + delta_y};
}

void DrawGeometry::set_fill_color(const char* hex_color) {
    fill_color.web(hex_color);
}

void DrawGeometry::set_fill_color(int r, int g, int b) {
    fill_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void DrawGeometry::set_outline_color(const char* hex_color) {
    outline_color.web(hex_color);
}

void DrawGeometry::set_outline_color(int r, int g, int b) {
    outline_color = SWWTool.rgb_to_vex_color(r, g, b);
}

void DrawGeometry::set_outline_width(int width) { outline_width = width; }

void DrawGeometry::draw_ellipse(int center_x, int center_y,
                                int short_axis_length, int long_axis_length,
                                int rotation_angle) {
    float a = long_axis_length / 2;
    float b = short_axis_length / 2;

    // 绘制椭圆轮廓
    SWWBrain.Screen.setPenColor(outline_color);
    for (int y = -b; y <= b; y++) {
        // 计算椭圆边界上的x值
        float x_boundary = a * sqrt(1 - (y * y) / (float)(b * b));

        std::array<float, 2> dot_left_rotated =
            rotate_coordinate(-x_boundary, y, rotation_angle);
        std::array<float, 2> dot_right_rotated =
            rotate_coordinate(x_boundary, y, rotation_angle);

        std::array<float, 2> dot_left_moved =
            move_coordinate(center_x, center_y, dot_left_rotated);
        std::array<float, 2> dot_right_moved =
            move_coordinate(center_x, center_y, dot_right_rotated);

        SWWBrain.Screen.drawLine(dot_left_moved[0], dot_left_moved[1],
                                 dot_right_moved[0], dot_right_moved[1]);
    }
    // 绘制椭圆内部
    a = a - outline_width / 2;
    b = b - outline_width / 2;

    SWWBrain.Screen.setPenColor(fill_color);
    for (int y = -b; y <= b; y++) {
        // 计算椭圆边界上的x值
        float x_boundary = a * sqrt(1 - (y * y) / (float)(b * b));

        std::array<float, 2> dot_left_rotated =
            rotate_coordinate(-x_boundary, y, rotation_angle);
        std::array<float, 2> dot_right_rotated =
            rotate_coordinate(x_boundary, y, rotation_angle);

        std::array<float, 2> dot_left_moved =
            move_coordinate(center_x, center_y, dot_left_rotated);
        std::array<float, 2> dot_right_moved =
            move_coordinate(center_x, center_y, dot_right_rotated);

        SWWBrain.Screen.drawLine(dot_left_moved[0], dot_left_moved[1],
                                 dot_right_moved[0], dot_right_moved[1]);
    }
}