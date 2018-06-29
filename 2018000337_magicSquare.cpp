#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int a[99][99], i, j, k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
	j = (n - 1) / 2;
	a[0][j] = 1;

	k = 2;
	while (k <= n * n)
	{
		i = i - 1;
		j = j + 1;
		if ((i < 0) && (j == n))
		{
			i = i + 2;
			j = j - 1;
		}
		else
		{
			if (i < 0)
				i = n - 1;
			if (j > n - 1)
				j = 0;
		}
		if (a[i][j] == 0)
			a[i][j] = k;
		else
		{
			i = i + 2;
			j = j - 1;
			a[i][j] = k;
		}

		k++;
	}


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) {
			cout << a[i][j] << " " ;
		}
		cout << endl;
	}
	return 0;
}