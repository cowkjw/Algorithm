#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, m, r;
vector<int> graph[100001];
int vis[100001];
int cnt = 0;

void DFS(int start)
{
	vis[start] = ++cnt;
	for (const auto& i :  graph[start])
	{
		if (vis[i] == 0)
		{
			DFS(i);
		}
	}
}
int main()
{
	cin >> n>>m>>r;

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
	DFS(r);
	for (int i = 1; i <= n; i++)
	{
		cout << vis[i] << '\n';
	}
	return 0;
}