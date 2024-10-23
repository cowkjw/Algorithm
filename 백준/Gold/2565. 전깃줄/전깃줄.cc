#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define INF 987654321
using namespace std;

int dp[101];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i].first>>vec[i].second;
	}
	sort(vec.begin(), vec.end());

	fill(dp, dp + 101, 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vec[i].second > vec[j].second)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << n - *max_element(dp, dp + 101);
	return 0;
}