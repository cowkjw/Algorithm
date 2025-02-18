#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>

using namespace std;
#define INF 987654321
const int dx[4]{ 1,-1,0,0 };
const int dy[4]{ 0,0,1,-1 };

int T, n, m,t, s, g, h;
struct Edge
{
	int v;
	int weight;
};
vector<Edge> edges[2001];

vector<int> dist;
vector<int> distG;
vector<int> distH;
auto Dijkstra(int start)
{
	vector<int> tmpDist(2001,INF);
	priority_queue<pair<int,int>> pq;
	pq.push({ 0,start });
	tmpDist[start] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (tmpDist[cur] < cost) continue;

		for (const auto& edge : edges[cur])
		{
			int nextNode = edge.v;
			int nextCost = edge.weight+cost;

			if (tmpDist[nextNode] >nextCost)
			{
				tmpDist[nextNode] = nextCost;
				pq.push({ -nextCost,nextNode });
			}
		}
	}
	return tmpDist;
}
int main()
{
	cin >> T;
	while (T--)
	{

		cin >> n >> m >> t;
		cin >> s >> g >> h; // 예술가 위치 , g,h 사이로 지나감 (즉 g,h와 연결된 간선으로 이동)
		for (int i = 1; i <= n; i++)
		{
			fill(edges[i].begin(), edges[i].end(), Edge{ 0, 0 });
		}
		int ghDist = 0;
		for (int i = 0; i < m; i++)
		{
			int u, v, d;
			cin >> u >> v >> d;

			edges[u].push_back({ v,d });
			edges[v].push_back({ u,d });

			if (u == g && v == h
				||u == h && v == g) ghDist = d;
		}

		dist = Dijkstra(s);
		distG = Dijkstra(g);
		distH = Dijkstra(h);
		vector<int> ans;
		for (int i = 0; i < t; i++) // 도착지 후보
		{
			int des;
			cin >> des;

			// s에서 시작해서 start간 가중치 == s->g까지 + g->h + h->des 
			// s에서 시작해서 start간 가중치 == s->h까지 + h->g + g->des 
			if (dist[des] == distG[s] + ghDist + distH[des]
				|| dist[des] == distH[s] + ghDist + distG[des])
			{
				ans.push_back(des);
			}
		}

		sort(ans.begin(), ans.end());
		for (const int node : ans) cout << node << " ";
		cout << '\n';
	}

	return 0;
}
