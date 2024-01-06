#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "./color.h"

#include "./tests/console_test.cpp"

namespace TestRunner {

void run() {
    TestSuite console_testsuite = console_init();
    std::cout << "Testing " << console_testsuite.name << "..." << std::endl;
    for(int i = 0; i < console_testsuite.tests.size(); i++) {
        std::cout << "\t";
        Color::print(Color::WHITE, Color::NONE, Color::BOLD, console_testsuite.name);
        std::cout << "::" << console_testsuite.tests[i].name << " => ";
        if(console_testsuite.tests[i].ptr()) {
            Color::print(Color::GREEN, Color::NONE, Color::BOLD, "PASSED");
        } else {
            Color::print(Color::RED, Color::NONE, Color::BOLD, "FAILED");
        }
        std::cout << std::endl;
    }
}

};
