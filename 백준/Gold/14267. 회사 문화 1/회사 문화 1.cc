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

int n, m;
vector<int> tree[100001];
int ans[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int u;
		cin >> u; // 해당 i번째의 부모
		if (u != -1)
			tree[u].push_back(i); // 어차피 계속 내려가기만 할거니까 둘이 쌍방향은 안해도 괜춘
	}

	for (int i = 0; i < m; i++)
	{
		int u, w;
		cin >> u >> w;
		ans[u] += w;
	}

	vector<int> vis(n + 1);
	stack<int> s;
	s.push(1);

	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		vis[cur] = 1;

		for (auto& node : tree[cur])
		{
			if (vis[node]) continue;

			ans[node] += ans[cur];

			s.push(node);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}
