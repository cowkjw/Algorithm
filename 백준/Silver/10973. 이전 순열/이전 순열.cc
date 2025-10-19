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

	int ans = -1;

	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	if (prev_permutation(arr.begin(), arr.end())) 
	{
		for (int x : arr)
			cout << x << ' ';
	}
	else 
	{
		cout << -1;
	}

	return 0;
}
