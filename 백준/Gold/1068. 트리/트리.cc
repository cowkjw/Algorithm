#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, m;

vector<int> tree[51];
int cnt;
void go(int node)
{
	if (tree[node].size() == 0)
	{
		cnt++;
		return;
	}

	for (const auto& leaf : tree[node])
	{
		go(leaf);
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	int a = 0;

	for (int i = 0; i < n; i++)
	{
		int tRoot;
		cin >> tRoot;

		if (tRoot == -1)
		{
			a = i;
			continue;
		}
		tree[tRoot].push_back(i);
	}

	cin >> m;
	if (m == a)
	{
		cout << 0;
		exit(0);
	}
	for (auto& leaf : tree[m])
	{
		for (auto& l : tree[leaf])
		{
			tree[l].clear();
		}
	}
	tree[m].clear();
	for (auto& node : tree)
	{
		for (auto it = node.begin(); it != node.end(); ++it)
		{
			if (*it == m)
			{
				node.erase(it);
				break;
			}
		}
	}

	go(a);

	cout << cnt;
	return 0;
}