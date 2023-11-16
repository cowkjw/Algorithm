#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

vector<pair<int,int>> graph[50001];
int n, m;
int dist[50001];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	fill(dist, dist + 50001, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist[node] < cost) continue;
		for (auto i : graph[node])
		{
			int nCost = i.second+cost;
			int next = i.first;

			if (dist[next] > nCost)
			{
				dist[next] = nCost;
				pq.push({ -nCost,next });
			}
		}
	}
	cout << dist[n];
	return 0;
}
