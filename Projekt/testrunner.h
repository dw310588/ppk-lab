#pragma once

#include <string>
#include <vector>

struct TestCase {
    std::string name;
    bool (*ptr)();
};

struct TestSuite {
    std::string name;
    std::vector<TestCase> tests;
};
