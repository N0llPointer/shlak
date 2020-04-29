#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

double du(double x, double u) {
	return x + cos(u / 2.25);
}
double Euler(double a, double n, double h);
double Runge_Kutta(double a, double n, double h);
double Adams(double a, double n, double h);

int main(){
	setlocale(LC_ALL, "Rus");
	double a = 1.4, b = 2.4, h = 0.001;
	double n = (b - a) / h;
	Euler(a, n, h);
	Runge_Kutta(a, n, h);
	Adams(a, n, h);
	_getch();
	return 0;
}

double Euler(double a, double n, double h){
	double x, u;
	x = a, u = 2.2;
	int j = 0;
	for (int i = 1; i <= n; i++){
		j++;
		x = x + h;
		u = u + h * du(x, u);
	}
	cout << "\nМетод Эйлера: " << "x = " << setw(4) << x << " u = " << setw(6) << u << endl;
	return 0;
}

double Runge_Kutta(double a, double n, double h){
	double x, u, u1, u2, u3, u4;
	x = a, u = 2.2;
	int j = 0;
	for (int i = 1; i <= n; i++){
		j++;
		x = x + h;
		u1 = h * du(x, u);
		u2 = h * du(x + h / 2, u + u1 / 2);
		u3 = h * du(x + h / 2, u + u2 / 2);
		u4 = h * du(x + h, u + u3);
		u = u + (u1 + 2 * u2 + 2 * u3 + u4) / 6;
	}
	cout << "\nМетод Рунге Кутта: " << "x = " << setw(4) << x << " u = " << setw(6) << u << endl;
	return 0;
}

double Adams(double a, double n, double h){
	double k1, k2, k3;
	double x, u, deltu;
	x = a, u = 2.2;
	int j = 0;
	for (int i = 1; i <= n; i++){
		j++;
		k1 = du(x + 2 * h, u + 2 * h) * h;
		k2 = du(x + h, u + h) * h;
		k3 = du(x, u) * h;
		deltu = (23 * k1 - 16 * k2 + 5 * k3) / 12;
		x = x + h;
		u = u + deltu;
	}
	cout << "\nМетод Адамса: " << "x = " << setw(4) << x << " u = " << setw(6) << u << endl;
	return 0;
}
