#include <iostream>
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

Console console_init_test() {
    Console cons;
    cons.mode = TEST;
    return cons;
}

Console console_init_dev() {
    Console cons;
    cons.mode = DEV;
    return cons;
}

Console console_init_prod() {
    Console cons;
    cons.mode = PROD;
    return cons;
}

void console_start_reading(Console& cons,void (*func)(Console& cons)) {
    while(std::getline(std::cin,cons.curr_line)) {
        func(cons);
    }
}

};

void my_tmp_func(Console::Console& cons) {
    std::cout << cons.curr_line << std::endl;
}

int main() {
    Console::Console cons = Console::console_init_dev();
    Console::console_start_reading(cons,&my_tmp_func);
    return 0;
}
