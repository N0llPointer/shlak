#include <iostream>
#include <conio.h>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

float funkf(float x);
float L, tau, lamda, h, T, a = 8.0, b=3.0, c=20.0, d=0.15, betta[9999], gamma[9999], alfa[9999], X[9999], V[9999];
int i, j, n, m;
float x[9999], t[9999], u[9999][9999];

int main() {
	setlocale(LC_ALL, "Rus");
	L = 1;
	cout << "Введите количество значений по х:" << endl;
	cin >> n;
	cout << "Введите максимальную температуру t:" << endl;
	cin >> T;
	cout << "Введите шаг по температуре:" << endl;
	cin >> tau;
	//cout << "Введите параметры a, b, c, d:" << endl;
	//cin >> a >> b >> c >> d;
	m = T / tau + 1;
	h = L / n;
	lamda = tau / (h * h);
	for (i = 1; i < n + 1; i++) {
		x[i] = (i - 1) * h;
	}
	for (j = 1; j < m; j++) {
		t[j] = (j - 1) * tau;
	}
	for (j = 0; j < m + 1; j++) {
		u[0][j] = funkf(x[0]);
		u[n][j] = b;
	}
	betta[0] = 1;
	gamma[0] = 0;
	for (j = 1; j < m - 1; j++) {
		for (i = 1; i < n; i++) {
			alfa[i] = lamda;
			gamma[i] = lamda;
			betta[i] = 1 - 2 * lamda;
			X[0] = 0;
			V[0] = u[0][j];
			X[i] = lamda / (1 + 2 * lamda - lamda * X[i - 1]);
			V[i] = (u[i][j - 1] + lamda * V[i - 1]) / (1 + 2 * lamda + lamda * X[i - 1]);
			u[i][j] = x[i];
		}
		for (i = n; i > 1; i--) {
			u[i - 1][j] = X[i - 1] * u[i][j] + V[i - 1];
		}
	}
	for (i = 0; i < n + 1; i++) {
		for (j = 0; j < m; j++) {
			cout << "u[" << i << "][" << j << "]=" << u[i][j] << endl;
		}
	}
	system("pause");
}

float funkf(float x) {
	float m = -10000;
	if (x >= 0 && x <= 1) {
		if (x < d) {
			m = ((c-a)/d)*x + a;
		}
		else if (x > d) {
			m = ((b - c) / (1 - d)) * (x - d);
		}
		else if (x == d)
			m = c;
	}
	return m;
}
