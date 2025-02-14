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
bool vis[101];
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
		fill(vis, vis + 101, false);
		queue<pair<int, int>>q;
		q.push({ i,0 });
		vis[i] = true;
		int cnt = 0;
		while (!q.empty())
		{
			int cur = q.front().first;
			int cost = q.front().second;
			cnt += cost;
			q.pop();
			for (const auto& nextNode : graph[cur])
			{
				int nextCost = cost + 1;

				if (vis[nextNode]) continue;

				vis[nextNode] = true;
				q.push({ nextNode, nextCost });
			}
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