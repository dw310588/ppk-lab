#pragma once

#include <iostream>

namespace Color {

enum Palette {
    NONE,
    DEFAULT,
    BLACK,
    WHITE,
    RED,
    GREEN,
    ORANGE,
    BLUE,
    MAGENTA,
    CYAN
};

enum Font {
    NORMAL,
    BOLD
};

int pallette_fg_to_str(Palette color);

int pallette_bg_to_str(Palette color);

void print(Palette fg, Palette bg, Font font, std::string text);

};
