#include <iostream>
#include <string>

#include "./color.h"

#define ERR_BAD_COMMAND 1
#define EXIT_COMMAND 2

namespace Console {

struct Console {
    std::string curr_line;
};

Console console_init() {
    Console cons;
    return cons;
}

void console_start_reading(Console& cons,int (*func)(Console& cons)) {
    while(std::getline(std::cin,cons.curr_line)) {
        int result = func(cons);
        if(result == ERR_BAD_COMMAND) {
            const std::string err_msg = "ERR::BAD COMMAND";
            Color::print(Color::RED, Color::NONE, Color::BOLD, err_msg);
            std::cout << std::endl;
        } else if(result == EXIT_COMMAND) {
            break;
        }
    }
}

};

void my_tmp_func(Console::Console& cons) {
    std::cout << cons.curr_line << std::endl;
}
