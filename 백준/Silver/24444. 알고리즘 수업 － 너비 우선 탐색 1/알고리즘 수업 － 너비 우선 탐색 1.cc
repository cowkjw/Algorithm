#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <numeric>
using namespace std;
#define INF 987654321
const int dx[4]{ 1,-1,0,0 };
const int dy[4]{ 0,0,1,-1 };

vector<int> graph[100001];
int vis[100001];
int main()
{
	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	queue<int> q;
	q.push({ r });
	vis[r] = 1;
	int visCnt = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (const auto ne : graph[cur])
		{
			if (!vis[ne])
			{
				vis[ne] =++visCnt;
				q.push(ne);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << vis[i] << '\n';
	}

	return 0;
}
