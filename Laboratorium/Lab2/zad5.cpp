#include <iostream>
#include <cmath>

int main() {
  int a,b,c,delta;
  float x1,x2;

  std::cout << "Podaj kolejne trzy wspolczynniki" << std::endl;
  std::cin >> a >> b >> c;

  delta = std::pow(b,2) - 4*a*c;
  delta = std::sqrt(delta);
  x1 = (-b-delta) / 2.*a;
  x2 = (-b+delta) / 2.*a;

  std::cout << "x1 = " << x1 << std::endl;
  std::cout << "x2 = " << x2 << std::endl;

  return 0;
}
