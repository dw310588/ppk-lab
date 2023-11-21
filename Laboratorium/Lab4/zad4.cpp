#include <iostream>
#include <iomanip>

int main() {
  int arr[10][10];

  for(int i = 1; i <= 10; i++) {
    for(int j = 1; j <= 10; j++) {
      arr[i-1][j-1] = i*j;
      std::cout << std::setw(5) << arr[i-1][j-1];
    }
    std::cout << std::endl;
  }

  return 0;
}
