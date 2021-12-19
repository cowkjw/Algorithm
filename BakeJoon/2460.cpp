#include <iostream>

using namespace std;


int main()
{
	int N, _N;
	int Max = 0;
	int temp = 0;

	for (int i = 0; i < 10; i++)
	{
		cin >> N >> _N;
		temp +=(_N - N);
		if (temp > Max)
			Max = temp;
	}
	cout << Max;
	return 0;
}


