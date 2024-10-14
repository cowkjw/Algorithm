#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;
int n, m;
vector<int> graph[101];
bool vis[101];

void DFS(int node)
{
	vis[node] = 1;

	for (int i = 0; i < graph[node].size(); i++)
	{
		if (vis[graph[node][i]]) continue;
		DFS(graph[node][i]);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	DFS(1);
	cout << accumulate(vis, vis + 101, -1);
	return 0;
}