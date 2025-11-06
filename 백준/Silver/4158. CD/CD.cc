#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };

int parent[1001];

int Find(int u)
{
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v)
{
	u = Find(u);
	v = Find(v);
	if (u != v)
		parent[u] = v;
}


int n, m;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);



	while (true)
	{

	cin >> n >> m;
	if (n == 0 && m == 0) break;
	unordered_map<int, int> um;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		um[num]++;
	}

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		um[num]++;
		if (um[num] >= 2) ans++;
	}
	cout << ans<<'\n';
	}
	return 0;
}
