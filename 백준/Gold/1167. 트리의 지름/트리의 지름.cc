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
using namespace std;

int n;

int ans,farNode;
bool vis[100001];
vector < pair<int, int>> vec[100001];
void DFS(int node, int cost)
{
	vis[node] = true;
	if (ans < cost)
	{
		ans = cost;
		farNode = node;
	}
	for (const auto& nextNode : vec[node])
	{
		if (vis[nextNode.first])continue;
		DFS(nextNode.first, cost + nextNode.second);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		while (true)
		{
			int a, cost;
			cin >> a;
			if (a == -1) break;
			cin >> cost;
			vec[v].push_back({ a, cost });
			vec[a].push_back({ v, cost });
		}
	}
	DFS(1, 0);
	fill(vis, vis + 100001, false);
	DFS(farNode, 0);
	cout << ans;
	return 0;
}