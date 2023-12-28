#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <map>

void zad1() {
	int n;
	std::string filename;
	std::cin >> n >> filename;
	std::ofstream file(filename);
	for (int i = 1; i <= n; i++) {
		file << i << std::endl;
	}
	file.close();
}

void zad2() {
	std::string filename;
	std::cin >> filename;
	std::ifstream file(filename);
	std::string tmp;
	while (std::getline(file,tmp)) {
		std::cout << tmp << std::endl;
	}
	file.close();
}

void zad3() {
	int n;
	std::string filename;
	std::cin >> n >> filename;
	int *nums = new int[n];
	int tmp;
	std::ifstream file(filename);
	int i = 0;
	while (file >> tmp && i < n) {
		nums[i] = tmp;
		i++;
	}
	file.close();
}

void zad4() {
	std::vector<std::pair<std::string, int>> people;
	std::ifstream file("./zad4.txt");
	std::string tmp;
	while (std::getline(file,tmp)) {
		std::pair<std::string, int> new_pair;
		int i = 0;
		while (tmp[i] != ' ' && i < tmp.size()) {
			new_pair.first += tmp[i];
			i++;
		}
		std::string age_tmp;
		while (i < tmp.size()) {
			age_tmp += tmp[i];
			i++;
		}
		new_pair.second = std::stoi(age_tmp);
		people.push_back(new_pair);
	}
	for (int i = 0; i < people.size(); i++) {
		std::cout << std::setw(3) << people[i].second << " " << people[i].first << std::endl;
	}
}

void zad5() {
	std::map<char, int> chars;
	for (int i = 0; i < 26; i++) {
		chars.insert('a' + i, 0);
	}
	std::ifstream file;
	std::string tmp;
	while (getline(file, tmp)) {
	}

	for (int i = 0; i < 26; i++) {
		std::cout << (char)('a' + i) << " => " << chars['a'+i] << std::endl;
	}
}

int main() {
	zad5();
	return 0;
}