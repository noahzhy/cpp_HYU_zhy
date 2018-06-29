#include <iostream>
using namespace std;

int main ()
{
	int c = 0;
	cin >> c;
	int a[99];
	for (int i = 0; i < c; i++)
	{
		cin >> a[i];
	}

	int temp = 0;
	for (int i = 1; i < c; i++)
	{
		for (int k = 0; k < c - i; k++)
		{
			if (a[k] > a[k + 1])
			{
				temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
			}

		}

	}

	for (int i = 0; i < c; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;

	return 0;
}
