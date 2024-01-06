#pragma once

#include "../console.h"
#include "../testrunner.h"

bool test_init_test() {
    Console::Console cons = Console::console_init_test();
    if(cons.mode != Console::TEST) {
        return false;
    }
    return true;
}

bool test_init_dev() {
    Console::Console cons = Console::console_init_dev();
    if(cons.mode != Console::DEV) {
        return false;
    }
    return true;
}

bool test_init_prod() {
    Console::Console cons = Console::console_init_prod();
    if(cons.mode != Console::PROD) {
        return false;
    }
    return true;
}

TestSuite console_init() {
    TestCase testcase_init_test;
    testcase_init_test.name = "init_test";
    testcase_init_test.ptr = &test_init_test;
    TestCase testcase_init_dev;
    testcase_init_dev.name = "init_dev";
    testcase_init_dev.ptr = &test_init_dev;
    TestCase testcase_init_prod;
    testcase_init_prod.name = "init_prod";
    testcase_init_prod.ptr = &test_init_prod;

    TestSuite testsuite_console;
    testsuite_console.name = "console";
    testsuite_console.tests.push_back(testcase_init_test);
    testsuite_console.tests.push_back(testcase_init_dev);
    testsuite_console.tests.push_back(testcase_init_prod);

    return testsuite_console;
}
