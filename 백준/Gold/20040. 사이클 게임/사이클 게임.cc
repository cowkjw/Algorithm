#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, m;
int parent[500001];

int Find(int x)
{
	if (x == parent[x])
	{
		return x;
	}

	return parent[x] = Find(parent[x]);
}

bool Union(int u, int v)
{
	u = Find(u);
	v = Find(v);

	if (u == v)
	{
		return false;
	}
	else
	{
		parent[u] = v;
		return true;
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);


	cin >> n >> m;

	for (int i = 0; i <n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (!Union(a, b))
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}