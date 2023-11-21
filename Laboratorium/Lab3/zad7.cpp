#include <iostream>

int main() {
  int n;

  std::cout << "Podaj wielkosc" << std::endl;
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j || j == (n-1-i))
        std::cout << "x";
      else
        std::cout << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
