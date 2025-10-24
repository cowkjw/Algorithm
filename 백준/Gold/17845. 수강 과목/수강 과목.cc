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

int dp[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m>>n;

	for (int i = 1; i <= n; i++)
	{
		int proirity, cost;
		cin >> proirity >> cost;
		for (int j = m; j >= cost; j--)
		{
			dp[j] = max(dp[j], dp[j - cost] + proirity);
		}
	}
	cout << dp[m];

	return 0;
}