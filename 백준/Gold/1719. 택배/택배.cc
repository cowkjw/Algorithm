#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321


using ll = long long;
using pii = pair<int, int>;
int first[201][201];
vector<vector<pair<int,int>>> v;
vector<int> dist;
int n, m;

void dijkstra(int start) 
{
	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		auto [cost, cur] = pq.top();
		pq.pop();
		if (dist[cur] < cost) continue;

		for (auto [nxt, w] : v[cur])
		{
			int ncost = cost + w;
			if (dist[nxt] > ncost) 
			{
				dist[nxt] = ncost;
				pq.push({ ncost, nxt });

				if (cur == start)
					first[start][nxt] = nxt;
				else 
					first[start][nxt] = first[start][cur];
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n>>m;


	v.resize(n + 1);
	dist.resize(n + 1, INF);
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({ b,w });
		v[b].push_back({ a,w });
	}

	for (int i = 1; i <= n; i++)
		dijkstra(i);

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			if (i == j) cout << "- ";
			else cout << first[i][j] << " ";
		}
		cout << "\n";
	}
    return 0;
}