#include <iostream>
#include <iomanip>

int main() {
  const int N = 4;
  int arr[N][N] = {0};

  int top = 0;
  int bottom = N;
  int left = 0;
  int right = N;

  int k = 1;
  while(left < right && top < bottom) {
    for(int i = left; i < right; i++)
      arr[top][i] = k++;
    top += 1;

    for(int i = top; i < bottom; i++)
      arr[i][right-1] = k++;
    right -= 1;

    for(int i = right-1; i >= left; i--)
      arr[bottom-1][i] = k++;
    bottom -= 1;

    for(int i = bottom-1; i >= top; i--)
      arr[i][left] = k++;
    left += 1;
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      std::cout << std::setw(5) << arr[i][j];
    }
    std::cout << std::endl;
  }

  return 0;
}
