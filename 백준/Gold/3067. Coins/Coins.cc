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

const int dx[4] = { 0,0, -1, 1 };
const int dy[4] = { -1,1,0,0 };

int n, m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<int> coin(n);
		for (int i = 0; i < n; i++) cin >> coin[i];
		cin >> m;
		vector<int> dp(m + 1);
		dp[0] = 1;
		for (int i = 0; i < n; i++)
		{
			int c = coin[i];
			for (int j = c; j <= m; j++)
			{
				dp[j] += dp[j - c];
			}
		}

		cout << dp[m] << '\n';
	}


	return 0;
}
