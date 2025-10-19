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
struct Belt
{
	bool robot = false;
	int life;// 내구도
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	vector<Belt> belts(2 * n);
	for (int i = 0; i < 2 * n; ++i)
		cin >> belts[i].life;
	int ans = 0,cnt = 0;
	while (true)
	{
		ans++;
		rotate(belts.rbegin(), belts.rbegin() + 1, belts.rend());
		belts[n - 1].robot = false; // 내리는 위치의 로봇은 항상 내림

		// 로봇 이동 (뒤에서 앞으로)
		for (int i = n - 2; i >= 0; --i)
		{
			if (belts[i].robot && !belts[i + 1].robot && belts[i + 1].life > 0) 
			{
				belts[i].robot = false;
				belts[i + 1].robot = true;
				belts[i + 1].life--;
				if (belts[i + 1].life == 0)
					cnt++;
			}
		}
		belts[n - 1].robot = false; // 내리는 위치 도달 시 로봇 내림

		// 로봇 올리기
		if (belts[0].life > 0) {
			belts[0].robot = true;
			belts[0].life--;
			if (belts[0].life == 0)
				cnt++;
		}

		// 내구도 0 개수 검사
		if (cnt >= k)
			break;
	}

	cout << ans;

	return 0;
}
