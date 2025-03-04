#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>

using namespace std;
#define INF 987654321
int n,m;
vector<vector<int>> graph(201, vector<int>(201));
int parent[201];

int Find(int a)
{
	if (parent[a] == a) return parent[a];
	return parent[a] = Find(parent[a]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n>>m;

	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> graph[i][j];

			if (graph[i][j])
			{
				Union(i, j);
			}
		}
	}

	int prevNode = 0;

	for (int i = 1; i <= m; i++)
	{
		int node = 0;
		cin >> node;
		if (prevNode != 0)
		{
			if (Find(node) != Find(prevNode))
			{
				cout << "NO";
				return 0;

			}
		}
		prevNode = node;
	}

	cout << "YES";

	return 0;
}
