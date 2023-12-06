#include <iostream>
#include <cmath>

struct Point {
	int x, y;
};

struct Rect {
	Point x1, x2;
};

struct Circle {
	Point center;
	int radius;
};

double point_dist(Point& p1, Point& p2) {
	double distance = std::pow((p2.x - p1.x),2) + std::pow((p2.y - p1.y),2);
	distance = std::sqrt(distance);
	return distance;
}

int rect_area(Rect& rect) {
	int a = std::abs(rect.x2.x - rect.x1.x);
	int b = std::abs(rect.x2.y - rect.x1.y);
	return a * b;
}

int bigger_rect(Rect& rect1, Rect& rect2) {
	int field1 = rect_area(rect1);
	int field2 = rect_area(rect2);
	return field1 > field2 ? 0 : 1;
}

int circle_area(Circle& circle) {
	return std::pow(circle.radius,2);
}

void print_rect(Rect& rect) {
	std::cout << "{";
	std::cout << rect.x1.x;
	std::cout << ",";
	std::cout << rect.x1.y;
	std::cout << ",";
	std::cout << rect.x2.x;
	std::cout << ",";
	std::cout << rect.x2.y;
	std::cout << "}";
	std::cout << std::endl;
}

std::string circle_state(Circle& c1, Circle& c2) {
	std::string result;
	if (c1.center.x == c2.center.x && c1.center.y == c2.center.y && c1.radius == c2.radius)
		result = "Okregi sie pokrywaja";
	return result;
}

void zad1() {
	Point p1;
	Point p2;
	std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
	double result = point_dist(p1, p2);
	std::cout << result << std::endl;
}

void zad2() {
	Rect rect;
	std::cin >> rect.x1.x >> rect.x1.y >> rect.x2.x >> rect.x2.y;
	int res = rect_area(rect);
	std::cout << res << std::endl;
}

void zad3() {
	Rect rect1;
	Rect rect2;
	std::cin >> rect1.x1.x >> rect1.x1.y >> rect1.x2.x >> rect1.x2.y;
	std::cin >> rect2.x1.x >> rect2.x1.y >> rect2.x2.x >> rect2.x2.y;
	int res = bigger_rect(rect1, rect2);
	if (res)
		print_rect(rect2);
	else
		print_rect(rect1);
}

void zad4() {
	Circle circle;
	std::cin >> circle.center.x >> circle.center.y >> circle.radius;
	int result = circle_area(circle);
	std::cout << result << "pi" << std::endl;
}

void zad5() {
	Circle c1;
	Circle c2;
	std::cin >> c1.center.x >> c1.center.y >> c1.radius;
	std::cin >> c2.center.x >> c2.center.y >> c2.radius;
	std::string result = circle_state(c1, c2);
	std::cout << result << std::endl;
}

int main() {
	zad5();

	return 0;
}