#include <iostream>

int main() {
  int a,b;

  std::cout << "Podaj kolejno dwie liczby" << std::endl;
  std::cin >> a >> b;

  int sum = a+b;

  std::cout << "Suma " << a << "+" << b << "=" << sum << std::endl;

  return 0;
}
