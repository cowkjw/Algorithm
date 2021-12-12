#include <iostream>

using namespace std;

int main()
{
	int Date, Count = 0;
	int Car[5];
	cin >> Date;

	for (int i = 0; i < 5; i++) {
		cin >> Car[i];
		if (Car[i] == Date)
		{
			Count++;
		}
	}

	cout<<Count;
}
