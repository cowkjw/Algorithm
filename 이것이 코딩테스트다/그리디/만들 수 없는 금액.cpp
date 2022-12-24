#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	vector<int> coins(n);
	for (int i = 0; i < n; i++)
		cin >> coins[i];

	sort(coins.begin(), coins.end());

	int canMake = 1;
	for (const auto& coin : coins)
	{

		if (canMake < coin)
			break;
		else
			canMake += coin;
	}
	cout << canMake;

	return 0;
}







