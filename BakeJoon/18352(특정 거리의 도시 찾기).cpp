#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

vector<int> graph[300001];
int d[300001];
int n, m, k, x;

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;

	pq.push({ 0,start });
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist)
			continue;
		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = dist + 1;
			if (cost < d[graph[now][i]])
			{
				d[graph[now][i]] = cost;
				pq.push({ -cost,graph[now][i] });
			}
		}
	}

}
void bfs(int start)
{
	queue<pair<int, int>> q;

	q.push({ start,0 });
	d[start] = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur.first].size(); i++)
		{
			int dist = cur.second + 1;

			if (d[graph[cur.first][i]] > dist)
			{
				d[graph[cur.first][i]] = dist;
				q.push({ graph[cur.first][i],dist });
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
	}

	fill(d, d + 300001, INF);

	//dijkstra(x);
	bfs(x);
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == k)
		{
			flag = true;
			cout << i << '\n';
		}
	}

	if (!flag)
		cout << -1;

}


