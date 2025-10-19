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


int n, p;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int ans = 0;

	int cnt = 0; // 3번이 넘으면 이제 계속 반복된다니까 그때부터 break하고 1인 애들만 찾아서 출력

	cin >> n >> p;
	unordered_map<int, int> mp;
	mp[n]++;
	while (true)
	{
		int temp = 0;
		while (n !=0)
		{
			temp+=(int)pow(n % 10, p);
			n /= 10;
		}

		n = temp;
		mp[n]++;
		if (mp[n] > 2) break;
	}
	for (auto& k : mp)
	{
		if (k.second == 1) ans++;
	}
	cout << ans;
	return 0;
}
