#include <iostream>

int main() {
  int min,max;
  float avg;
  int curr;
  char c;
  int is_first_iter = 1;

  std::cout << "Rozpocznij podawanie liczb" << std::endl;

  do {
    std::cin >> curr;
    if(is_first_iter) {
      min = curr;
      max = curr;
      is_first_iter = 0;
    } else if(curr < min) {
      min = curr;
    } else if(curr > max) {
      max = curr;
    }
    avg = (min+max) / 2.;

    std::cout << "Kontynuowac wypisywanie?(T/N) ";
    std::cin >> c;
  } while(c == 'T');

  std::cout << "Min: " << min << std::endl;
  std::cout << "Max: " << max << std::endl;
  std::cout << "Avg: " << avg << std::endl;

  return 0;
}
