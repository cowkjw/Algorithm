#include <iostream>

using namespace std;

int main()
{

	int N[8];
	int Min = 99;
	int sum = 0;

	for (int i = 0; i < 7; i++)
	{
		cin >>N[i];
	}
	
	
	for (int i = 0; i < 7; i++)
	{
		if (N[i] % 2 != 0)
		{
			sum += N[i];
			if (Min > N[i])
			{
				Min = N[i];
			}
		}
	}

	if (sum != 0) cout << sum << "\n" << Min;
	else cout << -1;

	
	return 0;

}