#include <iostream>
#include <string>

#include "./console.h"
#include "./color.h"

void loop(Console::Console& cons) {
    Color::print(Color::WHITE, Color::NONE, Color::BOLD, "Console::Console");
    std::cout << " => ";
    std::cout << cons.curr_line;
    std::cout << std::endl;
}

int main() {
    Console::Console cons = Console::console_init_dev();
    Console::console_start_reading(cons, &loop);

    return 0;
}
