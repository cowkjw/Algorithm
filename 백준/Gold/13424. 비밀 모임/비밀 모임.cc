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
int n, m,k;

void dijkstra(int start, vector<int>& sumDist)
{
	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	int minimum = INF;
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
				minimum = min(minimum, nxt);
				dist[nxt] = ncost;
				pq.push({ ncost, nxt });
			}
		}
	}
	for (int i = 1; i <= n; i++)
		sumDist[i] += dist[i];

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{

		cin >> n >> m;
		v.assign(n + 1, {});
		dist.assign(n + 1, INF);
		for (int i = 0; i < m; i++)
		{
			int a, b, w;
			cin >> a >> b >> w;
			v[a].push_back({ b,w });
			v[b].push_back({ a,w });
		}

		cin >> k;
		vector<int> sumDist(n + 1, 0);
		for (int i = 0; i < k; i++)
		{
			int start;
			cin >> start;
			dijkstra(start,sumDist);
		}
		int ansRoom = 1;
		int minSum = INF;
		for (int i = 1; i <= n; i++) 
		{
			if (sumDist[i] < minSum) 
			{
				minSum = sumDist[i];
				ansRoom = i;
			}
		}

		cout << ansRoom << "\n";
	}
    return 0;
}