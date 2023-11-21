#include <iostream>

int main() {
  int a,b,c;

  std::cout << "Podaj kolejne trzy liczby" << std::endl;
  std::cin >> a >> b >> c;

  float x = (c-b)/(float)a;

  std::cout << "x = " << x << std::endl;

  return 0;
}
