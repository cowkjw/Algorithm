#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<utility>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;


#define INF  9223372036854
int n, m;
long long dist[100001];
vector<pair<long long,long long>> graph[100001];
vector<int> visible(100001);
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> visible[i];
	}

	for (int i = 0; i < m; i++)
	{
		long long a, b, t;

		cin >> a >> b >> t;

		graph[a].push_back({ b,t });
		graph[b].push_back({ a,t });
	}


	fill(dist, dist + 100001, INF);

	priority_queue<pair<long long, long long>> pq;

	pq.push({ 0,0 });

	dist[0] = 0;

	while (!pq.empty())
	{
		long long cost = -pq.top().first;
		long long cur = pq.top().second;

		pq.pop();

		if (cost > dist[cur]) continue;

		for (const auto& next : graph[cur])
		{
			long long nextNode = next.first;
			long long nCost = cost + next.second;

			if (visible[nextNode] && nextNode != n - 1) continue;

			if (dist[nextNode] > nCost)
			{
				dist[nextNode] = nCost;
				pq.push({ -nCost ,nextNode });
			}
		}
	}

	cout << (dist[n - 1] == INF ? -1 : dist[n - 1]);

	return 0;
}