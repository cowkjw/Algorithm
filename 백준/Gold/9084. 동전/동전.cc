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
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const int hDx[] = { -2,-2,-1,-1,1,1,2,2 };
const int hDy[] = { -1,1,-2,2,-2,2,-1,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<int> v(n + 1);

		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
		
		}
		cin >> m;
		vector<int> dp(m + 1, 0);

		dp[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			int coin = v[i];
			for (int j = coin; j <= m; j++)
			{
				dp[j] += dp[j - coin];
			}
		}
		cout << dp[m] << "\n";
	}
	return 0;
}