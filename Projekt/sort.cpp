#include <iostream>
#include <vector>

namespace Sort {

int replace_into_increasing(int *a, int *b) {
    if(*a > *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
        return 1;
    }
    return 0;
}

int replace_into_decreasing(int *a, int *b) {
    if(*a < *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
        return 1;
    }
    return 0;
}

void bubble_sort(std::vector<int>& vec, int (*replace)(int *a, int *b)) {
    for(int i = 0; i < vec.size()-1; i++) {
        for(int j = i+1; j < vec.size(); j++) {
            int replace_res = replace(&vec[i], &vec[j]);
            if(!replace_res) {
                break;
            }
        }
    }
}

void bubble_sort(std::vector<int>& vec, bool reversed) {
    if(!reversed) {
        bubble_sort(vec, *replace_into_increasing);
    } else {
        bubble_sort(vec, *replace_into_decreasing);
    }
}

};
