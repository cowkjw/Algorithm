#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, m, r;

int item[101];
int d[101];
vector<pair<int, int>> graph[101];

void dijkstra(int start)
{
	priority_queue<pair<int, int>>pq;
	pq.push({ start,0 });

	d[start] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		if (d[cur] < cost)
			continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextCost = cost + graph[cur][i].second;

			if (nextCost < d[next])
			{
				d[next] = nextCost;
				pq.push({ next,-nextCost });
			}

		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
		cin >> item[i];

	for (int i = 0; i < r; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;

		graph[s].push_back({ e,w });
		graph[e].push_back({ s,w });
	}

	int ans =-1;
	int temp;
	for (int i = 1; i <= n; i++)
	{
		fill(d, d + 101, INF);
		dijkstra(i);
		temp = 0;
		for (int j = 1; j <= n; j++)
		{
			if (d[j] <= m)
				temp += item[j];
		}
		ans = max(ans, temp);
	}

	cout << ans;
}







