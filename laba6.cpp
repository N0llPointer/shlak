#include <iostream>
#include <conio.h>
#include <iomanip>
#include <math.h>
#include <windows.h>

using namespace std;

double u[20][2];

double func_f(double a, double b, double c, double x){
	double middle = ((c - b) / 2) + b;
	if (x <= b || x >= c)
		return 0;
	else if (x < middle)
		return (2 * a * (x - b)) / (c - b);
	else if (x == middle)
		return a;
	else if (x > middle)
		return (2 * a * (c - x)) / (c - b);
}

double func_g(double x){
		return 0;
}

void setka(double c, double x, double a, double b, int n){
	cout << setw(2) << "i" << setw(10) << "x" << setw(15) << "u[i][0]" << setw(15) << "u[i][1]" << endl;
	double h = 1.0 / n;
	for (int i = 0; i < n + 1; i++){
		u[i][0] = func_f(a, b, c, x);
		u[i][1] = u[i][0] + func_f(a, b, c, h) * func_g(x);
		cout << setw(2) << i << setw(10) << x << setw(15) << round(u[i][0] * 1000) / 1000 << setw(15) << round(u[i][1] * 1000) / 1000 << endl;
		x += h;
	}
}

int main(){
	setlocale(LC_ALL, "Rus");
	double a = 1.0, b = 0.05, c = 0.45, x = 0;
	int n;
	cout << "Введите количество отрезков: ";
	cin >> n;
	setka(c, x, a, b, n);
	_getch();
	return 0;
}
