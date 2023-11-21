#include <iostream>

int main() {
  const int ARR_SIZE = 9;
  int arr[ARR_SIZE] = {-3,1,6,2,12,-10,4,13,24};

  for(int i = 0; i < ARR_SIZE; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;

  int i = 0;
  while(i < ARR_SIZE - i - 1) {
    int tmp = arr[i];
    arr[i] = arr[ARR_SIZE - i - 1];
    arr[ARR_SIZE - i - 1] = tmp;
    i++;
  }

  for(int i = 0; i < ARR_SIZE; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;

  std::cout << std::endl;
}
