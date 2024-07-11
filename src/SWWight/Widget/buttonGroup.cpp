#include "SWWight/Widget/buttonGroup.h"

#include "algorithm"

using namespace SWWight;

/// --------------Button Class Functions--------------
buttonGroup::buttonGroup(std::vector<button *> button_group, int selected_max)
    : button_member(button_group),
      selected_button_max(selected_max)

{}

void buttonGroup::set_button_group_position(int delta_x, int delta_y) {
    for (int i = 0; i < button_member.size(); i++) {
        int x_pre = button_member[i]->get_x_position();
        int y_pre = button_member[i]->get_y_position();

        button_member[i]->set_button_position(x_pre + delta_x, y_pre + delta_y);
    }
}

void buttonGroup::set_button_group_color(const char *hex_color) {
    for (int i = 0; i < button_member.size(); i++) {
        button_member[i]->set_button_default_color(hex_color);
    }
}

void buttonGroup::set_button_group_color(int r, int g, int b) {
    for (int i = 0; i < button_member.size(); i++) {
        button_member[i]->set_button_default_color(r, g, b);
    }
}

void buttonGroup::set_button_group_outline_width(int width) {
    for (int i = 0; i < button_member.size(); i++) {
        button_member[i]->set_outline_width(width);
    }
}

void buttonGroup::set_button_group_outline_color(const char *hex_color) {
    for (int i = 0; i < button_member.size(); i++) {
        button_member[i]->set_outline_default_color(hex_color);
    }
}

void buttonGroup::set_button_group_outline_color(int r, int g, int b) {
    for (int i = 0; i < button_member.size(); i++) {
        button_member[i]->set_outline_default_color(r, g, b);
    }
}

int buttonGroup::determine_pressing_button() {
    for (int i = 0; i < button_member.size(); i++) {
        if (button_member[i]->determine_pressing()) {
            return i;
        }
    }
    return -1;
}

std::vector<int> buttonGroup::determine_selected_button() {
    int pressing_button_index = determine_pressing_button();

    if (pressing_button_index != -1) {
        // check whether the button is in the vector
        // if it is in the vector, delete it
        // to make sure the selectedbutton can turn unselected
        std::vector<int>::iterator it =
            std::find(selected_button_index.begin(),
                      selected_button_index.end(), pressing_button_index);
        if (it != selected_button_index.end()) {
            selected_button_index.erase(it);
        }

        // check whether the button is selected or not
        else if (button_member[pressing_button_index]->determine_selected()) {
            selected_button_index.push_back(pressing_button_index);
        }

        // if the vevtor is full, make the first button in the vevtor unselected
        // and delte it in the vector
        if (selected_button_index.size() > selected_button_max) {
            button_member[selected_button_index.front()]->set_select_state(
                false);
            selected_button_index.erase(selected_button_index.begin());
        }
    }
    return selected_button_index;
}

void buttonGroup::display() {
    for (int i = 0; i < button_member.size(); i++) {
        button_member[i]->display();
    }
}