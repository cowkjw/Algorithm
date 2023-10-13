#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
int t, n, d, c;
vector<pair<int,int>> com[100001];
int dist[100001];

void go(int start)
{
	priority_queue<pair<int, int>> pq;

	pq.push({ start, 0 });
	dist[start] = 0;
	while (!pq.empty())
	{
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i = 0;i< com[cur].size(); i++)
		{
			int next = com[cur][i].first;
			int nCost = com[cur][i].second;

			if (nCost+cost < dist[next])
			{
				dist[next] = nCost+cost;
				pq.push({ next,dist[next] });
			}
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;

	while (t--)
	{
		cin >> n >> d >> c;
		for (int i = 0; i < 100001; i++)
		{
			com[i].clear();
			dist[i] = INF;
		}
		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;

			com[b].push_back({ a,s });
		}
		go(c);
		int ret = 0;
		int tRet = -1;

		for (int i = 1; i <= n; i++)
		{
			if (dist[i] != INF)
			{
				ret++;
			    tRet = max(dist[i],tRet);
			}
		}
		cout << ret << " " << tRet << '\n';
		
	}
	return 0;
}
