#include <iostream>
#include <vector>
#include <ctime>
#include <climits>
#include <fstream>
#include <iomanip>

struct Point {
	int x, y;
};

struct Circle {
	Point center;
	int radius;
};

void vec_print(std::vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void arr_print(int arr[], int arr_size) {
	for (int i = 0; i < arr_size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void vec_populate_rand(std::vector<int>& vec, int n) {
	srand(time(0));
	int random;
	for (int i = 0; i < n; i++) {
		random = rand();
		std::cout << "random <= " << random << std::endl;
		vec.push_back(random);
	}
	vec_print(vec);
}

std::pair<int, int> arr_find_minmax(int arr[], int arr_size) {
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < arr_size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		} else if (arr[i] > max) {
			max = arr[i];
		}
	}
	return std::pair<int, int>(min, max);
}

std::vector<Circle> circle_gen(int n, int limit) {
	srand(time(0));
	int random;
	std::vector<Circle> result;
	for(int i = 0; i < n; i++) {
		Point point;
		Circle circle;
		random = rand() % limit;
		point.x = random;
		std::cout << "x => " << point.x << std::endl;
		random = rand() % limit;
		point.y = random;
		std::cout << "y => " << point.y << std::endl;
		random = rand() % limit;
		while (random == 0) {
			random = rand() % limit;
		}
		circle.center = point;
		circle.radius = random;
		std::cout << "radius => " << circle.radius << std::endl;
		result.push_back(circle);
	}
	return result;
}

int circle_area(Circle& circle) {
	return circle.radius * circle.radius;
}

void matrix_print(std::vector<std::vector<double>>& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			std::cout << matrix[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

void matrix_save(std::vector<std::vector<double>> matrix, std::string filename) {
	std::ofstream file(filename);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			file << std::fixed << std::setprecision(8) << matrix[i][j] << '\t';
		}
		file << std::endl;
	}
	file.close();
}

std::vector<std::vector<double>> matrix_read(std::string filename) {
	std::vector<std::vector<double>> res;
	std::ifstream file(filename);
	double curr;
	while (file >> curr) {
		std::cout << curr << " ";
	}
	std::cout << std::endl;
	file.close();
	return res;
}

void zad1() {
	int n;
	std::cin >> n;
	std::vector<int> vec;
	vec_populate_rand(vec, n);
}

void zad2() {
	const int ARR_SIZE = 5;
	int arr[ARR_SIZE] = { 1,2,3,4,5 };
	arr_print(arr, ARR_SIZE);
}

void zad3() {
	const int ARR_SIZE = 5;
	int arr[ARR_SIZE] = { 1,3,2,7,10 };
	std::pair<int, int> minmax = arr_find_minmax(arr, ARR_SIZE);
	std::cout << "arr => ";
	arr_print(arr, ARR_SIZE);
	std::cout << "min => " << minmax.first << std::endl;
	std::cout << "max => " << minmax.second << std::endl;
}

void zad4() {
	int n,limit;
	std::cin >> n >> limit;
	std::vector<Circle> res = circle_gen(n, limit);
	int min_area = INT_MAX;
	int min_idx = 0;
	for (int i = 0; i < res.size(); i++) {
		int area = circle_area(res[i]);
		std::cout << "area => " << area << std::endl;
		if (area < min_area) {
			min_area = area;
			min_idx = i;
		}
	}
	std::cout << min_idx << std::endl;
}

void zad5() {
	std::vector<std::vector<double>> matrix = {
		{1.132312213213,2.123131321312313,3.9123081831},
		{4.129381312,5.129312083,6.12312930213},
		{7.1290832190,8.12930218,9.12932231}
	};
	matrix_save(matrix, "zad5.txt");
}

void zad6() {
	std::vector<std::vector<double>> matrix = matrix_read("zad5.txt");
	matrix_print(matrix);
}

int main() {
	zad6();

	return 0;
}