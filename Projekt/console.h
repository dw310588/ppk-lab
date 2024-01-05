#pragma once

#include <string>

namespace Console {

enum Mode {
    TEST,
    DEV,
    PROD
};

struct Console {
    std::string curr_line;
    Mode mode;
};

Console console_init_test();

Console console_init_dev();

Console console_init_prod();

void console_start_reading(Console& cons,void (*func)(Console& cons));

};
