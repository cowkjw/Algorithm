#include <bits/stdc++.h>
using namespace std;

unsigned int line[10000];
unsigned int ans;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, N;
	unsigned int Max = 0;
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> line[i];
		Max = max(Max, line[i]);
	}
	unsigned int left = 1;
	unsigned int  right = Max;
	unsigned int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		unsigned int cnt = 0;

		for (int i = 0; i < K; i++)
		{
			cnt += line[i] / mid;
		}
		if (cnt >= N)
		{
			left = mid + 1;

			ans = max(ans, mid);
		}
		else
		{
			right = mid - 1;
		}

	}
	cout << ans;

	return 0;

}

