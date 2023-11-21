#include <ctime>
#include <iostream>
#include <cstdlib>

int main() {
  const int ARR_SIZE = 5;
  double arr[ARR_SIZE];

  srand(time(0));
  double rand = (double)std::rand() / RAND_MAX;

  for(int i = 0; i < ARR_SIZE; i++) {
    arr[i] = rand;
    rand = (double)std::rand() / RAND_MAX;
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl;
}
