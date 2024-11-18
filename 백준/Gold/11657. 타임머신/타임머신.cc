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
#include <climits>  
using namespace std;
#define INF  987654321123
int n, m;

vector<pair<int,int>> graph[501];
long long dist[501];
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	fill(dist, dist + 501, LLONG_MAX);

	dist[1] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int start = j;
			for (const auto& next : graph[start])
			{
				int nextNode = next.first;
				int cost = next.second+dist[start];
				if (dist[start] == LLONG_MAX) continue;

				if (dist[nextNode] > cost)
				{
					dist[nextNode] = cost;
				}
			}
		}
	}
	bool isNegative = false;
	for (int j = 1; j <= n; j++)
	{
		int start = j;
		for (const auto& next : graph[start])
		{
			int nextNode = next.first;
			long long cost = next.second + dist[start];
			if (dist[start] == LLONG_MAX) continue;

			if (dist[nextNode] > cost)
			{
				isNegative = true;
				break;
			}
		}
	}
	if (isNegative)
	{
		cout << -1;
		return 0;
	}
	for (int i = 2;i<=n;i++)
	{
		cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << '\n';
	}
	return 0;
}