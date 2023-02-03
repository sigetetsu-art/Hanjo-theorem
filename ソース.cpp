#include<iostream>
#include <cmath>
using namespace std;

static const double pi = 3.141592653589793;

double gx(double x) {
	return 0.5 * sin(pi * x/ 180) + 0.5 * (pi * x/180) - pi / 6;
}

double grad(double x) {
	return 0.5 * (pi / 180) * cos(pi * x/ 180) + 0.5 * (pi / 180);
}

int main() {
	double xn = 0.0;
	int i = 0;
	while (i < 100) {
		double x_n1 = xn - gx(xn) / grad(xn);
		if (abs(x_n1 - xn) < 0.00001) {
			break;
		}
		xn = x_n1;
		i = i + 1;
	}
	cout << "x_n = " << xn;
}