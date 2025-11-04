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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	vector<ll> dp(1000001, 0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (ll i = 4; i <= 1000000; i++)
	{
		dp[i] = (dp[i - 3]+ dp[i - 2] + dp[i - 1]) % 1000000009;
	}
	while (t--)
	{
		cin >> n;
	
		cout << dp[n] % 1000000009 << '\n';
	}
	return 0;
}
