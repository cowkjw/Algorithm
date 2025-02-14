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

vector<int> graph[101];
int dist[101];
int n, m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int ans = 101;
	int preMin = 1000000000;
	for (int i = 1; i <= n; i++)
	{
		fill(dist, dist + 101, 0);
		queue<pair<int, int>>q;
		q.push({ i,0 });
		dist[i] = 0;
		while (!q.empty())
		{
			int cur = q.front().first;
			int cost = q.front().second;
			q.pop();
			for (const auto& nextNode : graph[cur])
			{
				int nextCost = cost + 1;

				if (dist[nextNode]) continue;

				dist[nextNode] = nextCost;
				q.push({ nextNode, nextCost });
			}
		}

		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i != j) cnt += dist[j];
		}
		if (preMin > cnt)
		{
			preMin = cnt;
			ans = i;
		}
	}
	cout << ans;

	return 0;
}