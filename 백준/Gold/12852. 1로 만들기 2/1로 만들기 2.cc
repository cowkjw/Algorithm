#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321



int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector<int> vec(n + 1, 0);
	vector<int> dp(n + 1, 0);

	for (int i = 2; i <= n; i++)
	{
		int a = i - 1;
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
		{
			if (dp[i] > dp[i / 2] + 1)
			{
				a = i / 2;
			}
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			if (dp[i] > dp[i / 3] + 1)
			{
				a = i / 3;
			}
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		vec[i] = a;
	}
	cout << dp[n] << "\n";
	int cur = n;
	while (cur > 0)
	{
		cout << cur << " ";
		if (cur == 1) break;
		cur = vec[cur];
	}

	return 0;
}