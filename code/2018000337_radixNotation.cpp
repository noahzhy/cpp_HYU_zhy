#include <iostream>
using namespace std;
int main()
{
	int p, i = 0;

	int arry[99];

	cin >> p ;

	while (1) {
		cin >> arry[i];
		if (getchar() == '\n') {
			break;
		}
		i++;
	}

	for (int q = 0; q <= i; q++)
	{
		int  n, c, m = 0, s[100];
		n  =  arry[q];
		while (n != 0)
		{
			c = n % p;
			n = n / p;
			m++;
			s[m] = c;
		}

		for (int k = m; k >= 1; k--)
		{
			if (s[k] >= 10)
				cout << (char)(s[k] + 87);
			else
				cout << s[k] ;
		}
		cout << endl;
	}



	return 0;
}