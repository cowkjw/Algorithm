#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	bool isPrime = false;
	cin >> M >> N;

	if (M == 1) // 1 贸府
		M += 1;
	for (int i = M; i <= N; i++)
	{
		if (i < 4) // 3 贸府 
		{
			cout << i << "\n";
			continue;
		}
		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
			else
				isPrime = true;
		}
		if (isPrime)
			cout << i << "\n";
	
	

	}

	return 0;

}







