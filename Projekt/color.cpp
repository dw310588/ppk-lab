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

int pallette_fg_to_str(Palette color) {
    int result;
    switch(color) {
        case NONE:
            result = -1;
            break;
        case DEFAULT:
            result = 39;
            break;
        case BLACK:
            result = 30;
            break;
        case WHITE:
            result = 97;
            break;
        case RED:
            result = 91;
            break;
        case GREEN:
            result = 92;
            break;
        case ORANGE:
            result = 93;
            break;
        case BLUE:
            result = 94;
            break;
        case MAGENTA:
            result = 95;
            break;
        case CYAN:
            result = 96;
            break;
    }
    return result;
}

int pallette_bg_to_str(Palette color) {
    int result;
    switch(color) {
        case NONE:
            result = -1;
            break;
        case DEFAULT:
            result = 49;
            break;
        case BLACK:
            result = 40;
            break;
        case WHITE:
            result = 107;
            break;
        case RED:
            result = 101;
            break;
        case GREEN:
            result = 102;
            break;
        case ORANGE:
            result = 103;
            break;
        case BLUE:
            result = 104;
            break;
        case MAGENTA:
            result = 105;
            break;
        case CYAN:
            result = 106;
            break;
    }
    return result;
}

void print(Palette fg, Palette bg, Font font, std::string text) {
    int foreground = pallette_fg_to_str(fg);
    int background = pallette_bg_to_str(bg);
    if(foreground > 0) {
        std::cout << "\033[" << font << ";" << foreground << "m";
    }
    if(background > 0) {
        std::cout << "\033[" << background << "m";
    }
    std::cout << text;
    std::cout << "\033[m";
}

};
