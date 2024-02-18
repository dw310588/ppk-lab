#pragma once

#include <string>

#define ERR_BAD_COMMAND 1
#define EXIT_COMMAND 2

namespace Console {

enum Mode {
    TEST,
    DEV,
    PROD
};

struct Console {
    std::string curr_line;
};

Console console_init();

void console_start_reading(Console& cons,int (*func)(Console& cons));

};
