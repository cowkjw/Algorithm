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

int n, m, k;

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



int Cost(int from, int to) 
{
	if (from == 0) return 2;
	if (from == to) return 1;
	if (abs(from - to) == 2) return 4; // 반대편
	return 3; // 인접
}
int dp[100001][5][5]; // 현재 위치, 왼발 위치, 오른발 위치
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 초기에는 2의 힘을 사용
	// 인접하면 3의 힘 사용
	// 아예 반대면 4의 힘 사용
	// 같은 곳이면 1의 힘

	for (int i = 0; i <= 100000; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				dp[i][j][k] = INF;
	dp[0][0][0] = 0;

	int idx = 1;
	while (true)
	{
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int prev = dp[idx - 1][i][j];
				if (dp[idx - 1][i][j] == INF) continue;
				dp[idx][n][j] = min(dp[idx][n][j], prev + Cost(i, n));
				dp[idx][i][n] = min(dp[idx][i][n], prev + Cost(j, n));
			}
		}
		idx++;
	}
	int ans = INF;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			ans = min(ans, dp[idx - 1][i][j]);
		}
	}
	cout << ans;

	return 0;
}