#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

int n, m, d;

int dp[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n;

	vector<int> vec(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int val = vec[i];
		dp[i] = 1;
		for (int j = i - 1; j >=0; j--)
		{
			int prev = vec[j];
			if (prev < val)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int ans = -1;

	for (int i = 0; i < n; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}
