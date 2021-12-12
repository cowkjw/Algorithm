#include <iostream>

using namespace std;

int main()
{
	int N[5];
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> N[i];
		if (N[i] < 40) N[i] = 40;
		sum += N[i];
	}

	cout << sum/5;
}

