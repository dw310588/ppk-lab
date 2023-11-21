#include <iostream>

int main() {
  int min,max;
  char c;
  int k;

  std::cout << "Podaj zakres zgadywanej liczby" << std::endl;
  std::cin >> min >> max;

  while(min <= max) {
    k = (min+max) / 2;

    std::cout << "Czy zgadywana liczba jest mniejsza od " << k << "(T/N) ";
    std::cin >> c;
    std::cout << std::endl;

    if(c == 'T')
      max = k - 1;
    else
      min = k + 1;

  }

  std::cout << max << std::endl;

  return 0;
}
