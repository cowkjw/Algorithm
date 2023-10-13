#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
int n, m, x;
vector<pair<int, int>> adj[2][1001];
int dist[2][1001];

void go(int l, int start)
{
	priority_queue<pair<int, int>> pq;

	pq.push({ start, 0 });
	dist[l][start] = 0;
	while (!pq.empty())
	{
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (dist[l][cur] < cost) continue;

		for (int i = 0; i < adj[l][cur].size(); i++)
		{
			int next = adj[l][cur] [i] .first;
			int nCost = adj[l][cur][i].second;

			if (nCost + cost < dist[l][next])
			{
				dist[l][next] = nCost + cost;
				pq.push({ next,dist[l][next] });
			}
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n >> m >> x;
	for (int i = 0; i < 1001; i++)
	{
		dist[0][i] = INF;
		dist[1][i] = INF;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, s;
		cin >> a >> b >> s;

		adj[0][a].push_back({ b,s });
		adj[1][b].push_back({a,s });
	}
	go(0,x);
	go(1,x);
	int tRet = -1;

	for (int i = 1; i <= n; i++)
	{
		if (dist[0][i] != INF)
		{
			tRet = max(tRet, dist[0][i] + dist[1][i]);
		}
	}
	cout << tRet;

	return 0;
}
