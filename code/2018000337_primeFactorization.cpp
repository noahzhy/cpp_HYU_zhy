#include <iostream>
using namespace std;
int main()
{
	int N, p, e, fir;
	cin >> N;
	fir = 1;
	for (p = 2; p <= N; p++)
	{
		e = 0;
		while (N % p == 0)
		{
			N /= p;
			e++;
		}
		if (!e) {
			continue;
		};
		if (fir) {
			fir = 0;
		}
		else {
			cout << " x ";
		};
		cout << p << "^" << e;
	}
	cout << endl;
	return 0;
}