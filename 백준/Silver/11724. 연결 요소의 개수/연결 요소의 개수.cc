#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int n, m;
vector<int> graph[1001];
int vis[1001];
void go(int start)
{
	queue<int> q;
	q.push(start);
	vis[start] = 1;

	while (!q.empty())
	{
		int vertex = q.front();
		q.pop();

		for (auto i : graph[vertex])
		{
			if (vis[i]) continue;
			q.push(i);
			vis[i] = 1;
		}
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		go(i);
		ret++;
	}

	cout << ret;

	return 0;
}
