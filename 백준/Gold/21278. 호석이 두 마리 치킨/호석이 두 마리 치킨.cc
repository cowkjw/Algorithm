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

	cin >> n >> m;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1,INF));

	for (int i = 1; i <= n; i++) graph[i][i] = 0;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int j = 1; j <= n; j++)
			for (int i = 1; i <= n; i++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

	pii answer;
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int a = i, b = j;
			int cost = 0;

			for (int k = 1; k <= n; k++)
			{
				cost += min(graph[a][k], graph[b][k])*2;
			}

			if (ans > cost)
			{
				ans = cost;
				answer = { a,b };
			}

		}
	}
	cout << answer.first << " " << answer.second<<" "<<ans;

	return 0;
}
