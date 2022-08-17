#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
using namespace std;

vector<pair<int, int>> graph[1001];
int d[1001];
int n,m,city1,city2;
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

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		graph[s].push_back({ e,w });
	}

	cin >> city1 >> city2;
	fill(d, d + 1001, INF);

	dijkstra(city1);

	cout << d[city2];
}


