#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second


using namespace std;

int n, e, v1, v2;
vector<pair<int, int>> adj[801];
int d[801];

pair<bool, bool> check;
long long dijkstra(int start, int end)
{
	fill(d, d + 801, INF); // 무한대로 초기화

	priority_queue<pair<int, int>> pq;

	pq.push({ 0,start }); // 첫번째 정점 
	d[start] = 0; // 첫번째는 비용을 0으로 처리

	while (!pq.empty())
	{

		const auto dist = -pq.top().first; // 거리
		const auto now = pq.top().second; // 정점
		pq.pop();

		//if (d[now] < dist) continue;

		for (const auto& i : adj[now])
		{
			auto cost = dist + i.second; // 비용
			if (cost < d[i.first])
			{
				d[i.first] = cost;
				pq.push({ -cost, i.first });
			}
		}
	}
	return d[end];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		int u, v, c;

		cin >> u >> v >> c;

		adj[u].push_back({ v,c });
		adj[v].push_back({ u,c });
	}

	cin >> v1 >> v2;

	long long ans = min((dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n)), (dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n)));

	if (ans >= INF)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}

	return 0;
}
