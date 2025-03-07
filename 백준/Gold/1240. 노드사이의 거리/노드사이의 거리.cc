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

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };

struct Node
{
	int v, w;
};
int n,m;
vector<Node> tree[1001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n>>m;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		tree[u].push_back({ v, w });
		tree[v].push_back({ u, w });
	}


	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		vector<int> vis(n + 1);
		stack<Node> s;
		s.push({ u,0 });
		while (!s.empty())
		{
			Node cur = s.top();
			s.pop();
			vis[cur.v] = 1;

			if (cur.v == v)
			{
				cout << cur.w<<'\n';
				break;
			}

			for (const auto& node : tree[cur.v])
			{
				if (vis[node.v]) continue;

				vis[node.v] = 1;
				s.push({ node.v,cur.w + node.w });
			}
		}
	}


	return 0;
}
