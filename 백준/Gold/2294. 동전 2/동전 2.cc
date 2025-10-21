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


using ll = long long;
using pii = pair<int, int>;

int n, m,k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int parent[30001];
int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}


int dp[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> k;

	fill(dp, dp + 100001, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int coin;
		cin >> coin;
		for (int j = coin; j <= 100000; j++) // 코인 개수
		{
			dp[j] = min(dp[j], dp[j - coin] + 1);
		}
	}


	if (dp[k] == INF)
		cout << -1;
	else
		cout << dp[k];

	return 0;
}