#include "stdafx.h"
#include <iostream> 
#include <iomanip> 
#include <math.h> 

using namespace std;
double F(double x, double y, double z) {
	return (pow(x, 2) - z + 2);
}
int main() {
	double x0, y0, z0, x, y, z, xp, h, Hp, a, b;
	int kp, n;

	cout.precision(5); cout.setf(ios::left);

	cout << "VVedite n.y. x0,y0,z0" << endl; cin >> x0 >> y0 >> z0;

	cout << "vvedite a i b" << endl; cin >> a >> b;

	cout << "vvedite chislo razbien" << endl;
	cin >> n;

	cout << "Shag pechati" << endl; cin >> kp;

	cout << "x" << setw(10) << "y" << setw(10) << "z" << endl;
	cout << "_______________________________" << endl;
	cout << x0 << setw(10) << y0 << setw(10) << z0 << endl;

	h = (b - a) / n; Hp = kp * h;
	double k1, k2, k3, k4, l1, l2, l3, l4, dy0, dz0;
	x = x0; xp = x0;
	while (x < b) {
		xp = xp + Hp; while (x < xp)
		{
			l1 = h * (x0*x0 + 2 - z0);
			l2 = h * ((x0 + h / 2)*(x0 + h / 2) + 2 - z0 - l1 / 2);
			l3 = h * ((x0 + h / 2)*(x0 + h / 2) + 2 - z0 - l2 / 2);
			l4 = h * ((x0 + h )*(x0 + h ) + 2 - z0 - l3);
			k1 = h * z0; 
			k2 = h * (z0 + l1 / 2);
			k3 = h * (z0 + l2 / 2);
			k4 = h * (z0 + l3);
			dy0 = (k1 + 2 * k2 + 2 * k3 + k4)/6;
			dz0 = (l1 + 2*l2 + 2*l3 + l4)/6;
			x = x0 + h; y = y0 + dy0;
			z = z0 + dz0;
			x0 = x; y0 = y; z0 = z;
		}
		cout<< setw(10) << x << setw(10) << y << setw(10) << z << endl;
		
	} system("pause"); return 0;
}
