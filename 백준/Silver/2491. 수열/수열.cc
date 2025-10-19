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
#include <climits>

using namespace std;
using ll = long long;
#define INF 987654321

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };


int parent[1001];
struct Edge
{
	int u, v, cost;
	bool operator<(const Edge& other) const
	{
		return cost < other.cost;
	}
};

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


int n, k;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int ans = 1;

	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int inc = 1;
	int dec = 1;

	for (int i = 1; i < n; ++i)
	{
		if (arr[i] >= arr[i - 1])
			inc++;
		else
			inc = 1;

		if (arr[i] <= arr[i - 1])
			dec++;
		else
			dec = 1;
		ans = max({ inc,ans,dec });
	}

	cout << ans;

	return 0;
}
