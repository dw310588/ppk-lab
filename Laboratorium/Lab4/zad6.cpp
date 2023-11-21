#include <iostream>

void bubblesort(int arr[], int len) {
  for(int i = 0; i < len-1; i++) {
    for(int j = i+1; j < len; j++) {
      if(arr[i] > arr[j]) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}

void insertionsort(int arr[], int len) {
  for(int i = 1; i < len; i++) {
    int key = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j -= 1;
    }
    arr[j+1] = key;
  }
}

void selectionsort(int arr[], int len) {
  for(int i = 0; i < len-1; i++) {
    int min = i;
    for(int j = i+1; j < len; j++) {
      if(arr[min] > arr[j])
        min = j;
    }
    if(i != min) {
      int tmp = arr[i];
      arr[i] = arr[min];
      arr[min] = tmp;
    }
  }
}

void print_array(int arr[], int len) {
  for(int i = 0; i < len; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
}

int main() {
  const int ARR_SIZE = 5;
  int arr[ARR_SIZE] = {3,5,1,9,2};
  char c;

  std::cout << "Sortowana tablica: ";
  print_array(arr, ARR_SIZE);

  std::cout << "Sortowac bambelkowo, przez wstawianie czy wybieranie?(B/I/S) ";
  std::cin >> c;

  if(c == 'B')
    bubblesort(arr, ARR_SIZE);
  else if(c == 'I')
    insertionsort(arr, ARR_SIZE);
  else if(c == 'S')
    selectionsort(arr, ARR_SIZE);
  else {
    std::cout << "ERR: Nieprawidlowo wybrany algorytm sortowania" << std::endl;
    std::cout << "Wybrano: " << c << std::endl;
    std::cout << "OczekiwanoL B/I/S" << std::endl;
    return 1;
  }

  std::cout << "Wynik: ";
  print_array(arr, ARR_SIZE);

  return 0;
}
