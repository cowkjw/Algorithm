#include <bits/stdc++.h>
using namespace std;

int cnt[102];
int n, edge;
pair<int, int> target;
int v[102][102];
bool vis[102];

void BFS(int start)
{
	queue < int >q;
	q.push(start);
	vis[start] = true;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			if (v[cur][i] && !vis[i])
			{
				q.push(i);
				vis[i] = true;
				cnt[i] = cnt[cur] + 1;
			}
		}

	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;


	cin >> target.first >> target.second;
	cin >> edge;

	for (int i = 0; i < edge; i++)
	{
		int s, e;
		cin >> s >> e;
		v[s][e] = v[e][s] = 1;
	}
	BFS(target.first);
	if (cnt[target.second] == 0)
		cout << -1;
	else
		cout << cnt[target.second];
	return 0;


}

