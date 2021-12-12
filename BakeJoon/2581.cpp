#include <iostream>
using namespace std;

bool prime(int N)
{
	if (N == 1)
		return false;
	else if (N == 2)
		return true;
	else
	{
		for (int i = 2; i < N; i++)
		{
			if (N % i == 0)
				return false;
		}
		return true;
	}
}


int main()
{
	int N, M;
	int Min = 10001;
	int sum = 0;

	cin >> N >> M;

	for (int i = N; i <= M; i++)
	{
		if (prime(i))
		{
			sum += i;
			Min > i ? Min = i : Min = Min;
		}
	}

	if (sum != 0)
		cout << sum << "\n" << Min;
	else
		cout << "-1";


	return 0;
}


