#include <iostream>
#include <iomanip>

int main() {
  for(int i = 1; i <= 10; i++) {
    for(int j = 1; j <= 10; j++) {
      std::cout << std::setw(5);
      std::cout << i*j;
    }
    std::cout << std::endl;
  }

  return 0;
}
