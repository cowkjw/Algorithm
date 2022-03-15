#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long num;
	int cnt = 0;
	long long sum = 0;
	cin >> num;

	for (long long i = 1; i <= num; i++)
	{
		sum += i;
		if (sum > num)
		{
			break;
		}
		cnt++;
	}

	cout << cnt;

}




