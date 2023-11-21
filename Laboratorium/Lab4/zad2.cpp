#include <iostream>

int main() {
  const int ARR_SIZE = 5;
  int arr[ARR_SIZE] = {1,5,-2,3,8};
  int min;

  for(int i = 0; i < ARR_SIZE; i++) {
    if(i == 0) min = arr[i];
    else if(arr[i] < min) min = arr[i];
  }

  std::cout << "Min: " << min << std::endl;

  return 0;
}
