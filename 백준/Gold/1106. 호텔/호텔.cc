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


int dp[100001]; // 사람 수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m;


	for (int i = 0; i < m; i++)
	{
		int cost, person;
		cin >> cost >> person;
		for (int j = cost; j <= 100000; j++)
		{
			dp[j] = max(dp[j], dp[j - cost] + person);
		}
	}
	int ans = INF;
	for (int i = 0; i <= 100000; i++)
	{
		if (dp[i] >= n)
		{
			ans = min(ans, i);
		}
	}
	cout << ans;


	return 0;
}