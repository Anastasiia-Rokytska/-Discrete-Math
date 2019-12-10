#include <iostream>
#include <math.h>

using namespace std;

int factorial(int a)
{
	if (a == 1)
	{
		return a;
	}
	else if (a == 0)
	{
		return 1;
	}
	return a * factorial(a - 1);
}

long long int koef(int n, int d)
{
	return factorial(d) / (factorial(n) * factorial(d - n));
}

int main()
{

	long long int x, y;
	cout << "Enter x:";
	cin >> x;
	cout << "Enter y:";
	cin >> y;
	if (x == y) {
		cout << "(x - y)^11 = 0";
		return 0;
	}
	long long int binom = 0;
	for (int i = 0; i <= 11; ++i)
	{
		binom += koef(i, 11) * pow(x, i) * pow(-y, 11 - i);
	}
	cout << "(x - y)^11 = ";
	for (int i = 0; i < 11; ++i)
	{
		if (i % 2)
		{
			cout << " - ";
		}
		else
		{

			i == 0 ?
				cout << " "
				:
				cout << " + ";
		}
		cout << koef(i, 11) << " * (x^" << i << ") * (y^" << 11 - i << ")";
	}
	cout << " = " << binom << "\n";

	int a[50];

	int r;
	cout << "\n\n\n\nEnter r: " << endl;
	cin >> r;
	int n;
	cout << "Enter n: " << endl;
	cin >> n;
	
	if (r <= n) {
		for (int i = 0; i < r - 1; ++i)
		{
			a[i] = 1;
		}
		a[r - 1] = 0;
		bool finish = false;
		int key = 0;

		while (!finish)
		{
			for (int i = r - 1; i >= 0; --i)
			{
				if (a[i] < n)
				{
					a[i]++;
					for (int j = i + 1; j <= r; ++j)
					{
						a[j] = 1;
					}
					break;
				}
				if (i == 0) {
					finish = true;
					return 0;
				}
			}
			bool check = false;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < r; j++) {
					if (j != i && a[i] == a[j]) {
						check = true;
						break;
					}
				}
			}


			if (!check) {
				for (int i = 0; i < r; ++i)
				{
					if (a[i] == 0)
					{
						break;
					}
					else
					{
						cout << a[i] << " ";
					}
				}
				cout << endl;
			}
		}

	}
	else {
		cout << "Schedule of lexicographic order is impossible";
	}
	return 0;
}