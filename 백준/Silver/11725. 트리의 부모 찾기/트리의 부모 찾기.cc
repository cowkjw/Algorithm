#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second


using namespace std;

bool vis[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<list<int>> tree(n + 1);
	vector<int> answer(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}


	queue<int> q;

	vis[1] = true;
	q.push(1);

	while (!q.empty())
	{
		auto parent = q.front();
		q.pop();

		for (const auto& node : tree[parent])
		{
			if (!vis[node])
			{
				answer[node] = parent;
				vis[node] = true;
				q.push(node);
			}
		}
	}

	for (int i =2 ;i<=n;i++)
	{
		cout << answer[i]<< '\n';
	}
	return 0;
}
