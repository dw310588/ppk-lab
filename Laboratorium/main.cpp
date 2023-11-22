#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

double cube(double n) {
	double result = n*n*n;
	return result;
}

void zad1() {
	double n;
	double cubed;
	std::cout << "Podaj liczbe" << std::endl;;
	std::cin >> n;

	cubed = cube(n);

	std::cout << "Szescian liczby " << n << " to " << cubed << std::endl;
}

double power(double n, int p) {
	double curr = n;
	int i = 1;
	while (i < p) {
		curr *= n;
		i++;
	}
		
	return curr;
}

void zad2() {
	double n;
	int p;
	double result;

	std::cout << "Podaj kolejno liczbe i potege" << std::endl;
	std::cin >> n >> p;

	result = power(n, p);

	std::cout << n << " do potegi " << p << " to " << result << std::endl;
}

double calc_distance(double x1, double y1, double x2, double y2) {
	double result = std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2);
	result = std::sqrt(result);
	return result;
}

void zad3() {
	double x1, y1;
	double x2, y2;
	double distance;

	std::cout << "Podaj kolejno wspolrzedne dwoch punktow" << std::endl;
	std::cin >> x1 >> y1 >> x2 >> y2;

	distance = calc_distance(x1, y1, x2, y2);
	
	std::cout << "Odlegloscia miedzy punktami (" << x1 << "," << y1 << ") oraz (" << x2 << "," << y2 << ") jest " << distance << std::endl;
}

int occurrences_count(std::string& input) {
	int len = 0;
	for (int i = 0; i < input.size(); i++)
		if (input[i] == 'a') len++;
	return len;
}

void zad4() {
	std::string str;
	int len;

	std::cout << "Podaj lancuch znakowy" << std::endl;
	std::cin >> str;

	len = occurrences_count(str);

	std::cout << "Iloscia znakow a w " << str << " jest " << len << std::endl;
}

void fill_array(int arr[], int arr_len, int min, int max) {
	int diff = max - min + 1;
	for (int i = 0; i < arr_len; i++) {
		arr[i] = min + (i % diff);
	}
}

void print_array(int arr[], int arr_len) {
	for (int i = 0; i < arr_len; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void zad5() {
	const int ARR_SIZE = 15;
	int arr[ARR_SIZE];
	int min, max;
	
	std::cout << "Podaj przedzial wartosci" << std::endl;
	std::cin >> min >> max;

	print_array(arr,ARR_SIZE);
	fill_array(arr, ARR_SIZE, min, max);
	print_array(arr,ARR_SIZE);
}

void reverse_str(std::string& str) {
	int len = str.size();
	int i = 0;
	while (i < len - i) {
		char tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
}

void zad6() {
	std::string str;

	std::cout << "Podaj slowo" << std::endl;
	std::cin >> str;

	reverse_str(str);

	std::cout << str << std::endl;
}

void get_data(std::string& name, std::string& surname, int *age) {
	std::cout << "Podaj kolejno imie, nazwisko i wiek" << std::endl;
	std::cin >> name >> surname >> *age;
}

void zad8() {
	std::string name, surname;
	int age;

	get_data(name, surname, &age);

	std::cout << name << " " << surname << " " << age << std::endl;
}

void replace(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void zad9() {
	int a, b;

	std::cout << "Podaj kolejne dwie liczby calkowite" << std::endl;
	std::cin >> a >> b;

	std::cout << a << "," << b;
	replace(&a, &b);
	std::cout << " => " << a << "," << b << std::endl;
}

void print_array_recc(int arr[], int n) {
	if (n == 0) return;
	std::cout << arr[n - 1] << " ";
	print_array_recc(arr, n - 1);
}

void zad10() {
	const int ARR_SIZE = 5;
	int arr[ARR_SIZE] = { 1,2,3,4,5 };

	print_array_recc(arr, ARR_SIZE);
}

void zad7() {
	std::string str;
	
	std::cout << "Podaj wyraz" << std::endl;
	std::cin >> str;

	srand(time(0));
	int random = rand() % str.size();

	
}

int main() {
	int n;

	std::cout << "Podaj nr zadania" << std::endl;
	std::cin >> n;

	if (n == 1) zad1();
	else if (n == 2) zad2();
	else if (n == 3) zad3();
	else if (n == 4) zad4();
	else if (n == 5) zad5();
	else if (n == 6) zad6();
	else if (n == 8) zad8();
	else if (n == 9) zad9();
	else if (n == 10) zad10();

	return 0;
}