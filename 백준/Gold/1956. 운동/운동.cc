#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
int v, e;

int graph[401][401];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e;

	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			graph[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	} 

	for (int k = 1; k <= v; k++)
	{
		for (int i = 1; i <= v; i++)
		{
			for (int j = 1; j <= v; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int ret = INF;
	for (int i = 1; i <= v; i++)
	{
		ret = min(graph[i][i], ret);
	}
	if (ret == INF) cout << -1;
	else cout << ret;

	return 0;
}
