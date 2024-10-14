#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int n, m,r;
vector<int> graph[100001];
bool vis[100001];
int order[100001];
int main()
{
	cin >> n >> m>>r;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}


	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end(), greater<int>());
	}

	queue<int> q;
	q.push(r);
	vis[r] = 1;
	int cnt = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		order[cur] = ++cnt;
		

		for (const auto& next : graph[cur])
		{
			if (vis[next]) continue;

			vis[next] = 1;
			q.push(next);
		}
	}

	for (int i =1; i <= n; i++)
	{
		cout << order[i]<<'\n';
	}
	
	return 0;
}