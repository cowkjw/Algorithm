#include <iostream>

using namespace std;


int main()
{
	int N, K, i;

	int cnt = 0;
	cin >> N >> K;

	for ( i = 1; i <= N; i++)
	{
		if (N % i == 0)
		{
			cnt++;
		}
		if (K == cnt)
			break;
	}
	if (K == cnt)
		cout << i;
	else
		cout << "0";

	return 0;
}


