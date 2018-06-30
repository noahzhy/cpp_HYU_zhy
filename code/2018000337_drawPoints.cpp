#include <iostream>
using namespace std;
int main()
{
	string a[99][99];
	int x = 0, y = 0, max_x = 0, max_y = 0;
	while (1) {

		cin >> x >> y;
		if ((x == -1) && (y == -1))
		{
			break;
		}
		if (max_x < x)
		{
			max_x = x;
		}
		if (max_y < y)
		{
			max_y = y;
		}
		for (int i = 0; i <= y; i++)
		{
			for (int j = 0; j <= x; j++)
			{
				a[i][j] =  ".";

			}
		}
		a[y][x] = "*";
		for (int i = 0; i <= max_y; i++)
		{
			for (int j = 0; j <= max_x; j++)
			{

				cout << a[i][j];


			}
			cout << endl;
		}

	}
	return 0;
}