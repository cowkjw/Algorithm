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



bool dp[101][1001];
int n, m, d;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> d;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	dp[0][m] = 1;

	for (int i = 1; i <= n; i++)
	{
		int vol = vec[i-1]; // 현재 곡에서 처리해야하는 볼륨
		for (int j = 0; j <= d; j++)
		{
			if (!dp[i - 1][j]) continue; // 이전에 불가능한 볼륨
			if (vol + j <= d)
			{
				dp[i][vol + j] = 1;
			}

			if (j - vol >= 0)
			{
				dp[i][j - vol] = 1;
			}
		}
	}
	int ans = -1;

	for (int i = d; i >= 0; i--)
	{
		if (dp[n][i])
		{
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}
