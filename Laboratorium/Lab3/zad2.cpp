#include <iostream>

int main() {
  int n;

  std::cout << "Podaj ilosc wypisywanych liczb" << std::endl;
  std::cin >> n;

  int i = n;

  while(i > 0) {
    std::cout << i << std::endl;
    i--;
  }
}
