#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
using namespace std;

vector<pair<int, int>> graph[20001];
int d[20001];
int v, e, k;
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
			int cost = dist + graph[now][i].second;

			if (cost < d[graph[now][i].first])
			{
				d[graph[now][i].first] = cost;
				pq.push({ -cost,graph[now][i].first });
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e;
	cin >> k;

	for (int i = 0; i < e; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		graph[s].push_back({ e,w });
	}

	fill(d, d + 20001, INF);

	dijkstra(k);

	for (int i = 1; i <= v; i++)
	{
		if (d[i] == 987654321)
			cout << "INF" << '\n';
		else

			cout << d[i] << '\n';
	}
}


