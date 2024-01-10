#pragma once

#include <iostream>
#include <vector>

namespace Sort {

int replace_into_increasing(int *a, int *b);

void bubble_sort(std::vector<int>& vec, int (*replace)(int *a, int *b));

void bubble_sort(std::vector<int>& vec, bool reversed);

void bubble_sort(std::vector<int>& vec);

};
