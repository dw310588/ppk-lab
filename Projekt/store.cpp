#include <iostream>
#include <vector>

#include "./sort.h"

namespace Store {

enum SortMethod {
    BUBBLE_SORT_INC,
    BUBBLE_SORT_DECR
};

std::vector<int> Store;

void store_sort(SortMethod sort_method) {
    switch(sort_method) {
        case BUBBLE_SORT_INC:
            Sort::bubble_sort(Store, false);
        case BUBBLE_SORT_DECR:
            Sort::bubble_sort(Store, true);
    }
}

void store_print() {
    for(int i = 0; i < Store.size(); i++) {
        std::cout << Store[i] << " ";
    }
    std::cout << std::endl;
}

};
