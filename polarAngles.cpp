#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>  

# define M_PI          3.14159265358979323846

struct Point {
	int x, y;
	double angle;
	Point() {}
	Point(int _x, int _y) :x(_x), y(_y) {
		angle = atan2(_y, _x);
		if (angle < 0)
			angle = 2 * M_PI + angle;
	}
	friend std::ostream& operator<<(std::ostream& os, const Point& p) {
		os << p.x << " " << p.y;
		return os;
	}
};

bool comp(const Point &a, const Point &b) {
	if (a.angle == b.angle) {
		int da = a.x*a.x + a.y*a.y;
		int db = b.x*b.x + b.y*b.y;
		return da < db;
	}
	else return a.angle < b.angle;
}

class polarAngles {
	int N;
	std::vector<Point> points;
public:
	polarAngles() {}
	void read() {
		std::cin >> N;
		int x, y;
		for (int i = 0; i < N; ++i) {
			std::cin >> x >> y;
			points.push_back(Point(x, y));
		}
	}

	void sorting() {
		sort(points.begin(), points.end(), comp);
	}

	void print() {
		for (unsigned int i = 0; i < points.size(); ++i)
			std::cout << points[i] << std::endl;
	}
};

int main() {
	polarAngles p;
	p.read();
	p.sorting();
	p.print();

	return 0;
}