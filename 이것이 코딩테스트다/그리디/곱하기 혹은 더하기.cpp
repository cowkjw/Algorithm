#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string numbers;
	cin >> numbers;

	int ans = 0;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] - '0' <= 1 || ans <= 1)
		{
			ans += numbers[i] - '0';
		}
		else
		{
			ans *= numbers[i] - '0';
		}
	}
	cout << ans;

	return 0;
}







