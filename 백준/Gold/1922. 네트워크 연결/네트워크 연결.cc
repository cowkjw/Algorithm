#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 987654321
int v, e;
vector<pair<int, int>> graph[10001];
int vis[1001];
int ret;

void Prim()
{
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,1 });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (vis[cur]) continue;
		vis[cur] = 1;
		ret += cost;

		for (const auto& i : graph[cur])
		{
			if (vis[i.first]) continue;

			pq.push({ -i.second,i.first });
		}

	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v;
	cin >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	Prim();
	cout << ret;
	return 0;
}
