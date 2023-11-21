#include <iostream>

int main() {
  float a1,b1,c1;
  float a2,b2,c2;

  std::cout << "Podaj kolejno po 3 liczby dla dwoch rownan" << std::endl;
  std::cin >> a1 >> b1 >> c1;
  std::cin >> a2 >> b2 >> c2;

  float determinant = a1*b2 - a2*b1;
  float x,y;

  if(determinant != 0) {
    x = (c1*b2 - c2*b1) / determinant;
    y = (a1*c2 - a2*c1) / determinant;
  } else {
    std::cout << "Brak rozwiazan" << std::endl;
    return 0;
  }

  std::cout << "x = " << x << std::endl;
  std::cout << "y = " << y << std::endl;

  return 0;
}
