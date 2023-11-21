#include <iostream>
#include <cmath>

int main() {
  int n, a1, q;
  int curr, sum;
  int sum_by_formula;

  std::cout << "Podaj kolejno n, a1 oraz q" << std::endl;
  std::cin >> n >> a1 >> q;

  curr = a1;
  sum = 0;

  for(int i = 0; i < n; i++) {
    sum += curr;
    curr *= q;
  }

  sum_by_formula = 1 - std::pow(q,n);
  sum_by_formula = (a1*sum_by_formula) / (1 - q);

  std::cout << "Suma wyliczona dodajac kolejno: " << sum << std::endl;
  std::cout << "Suma wyliczona ze wzoru " << sum_by_formula << std::endl;

  return 0;
}
