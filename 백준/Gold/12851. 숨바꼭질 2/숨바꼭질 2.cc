#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
using namespace std;
const vector<pair<int, int>> dir{ {1,0} ,{-1,0} ,{0,1} ,{0,-1} };
int n,k,res=INF,m;
queue<int> q;
int dist[100001];
int vis[200000];
int cnt[200000];
void go(int x)
{
	q.push(x);
	vis[x] = 1;
	cnt[x] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : {cur + 1, cur - 1, cur * 2})
		{
			if (next >= 0 && next < 200000)
			{
				if (!vis[next])
				{
					q.push(next);
					vis[next] = vis[cur]+1;
					cnt[next] += cnt[cur];
				}
				else if (vis[next] == vis[cur] + 1)
				{
					cnt[next] += cnt[cur];
				}
			}
		}
	}
	return;
}
int main(void)
{
	cin >> n >> k;
	go(n);
	cout << vis[k] - 1 << '\n'<< cnt[k];
	return 0;
}
