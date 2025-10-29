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
using pii = pair<int, int>;
#define INF 987654321


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


int n, m, d;
bool prime[1000001]{ true, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	fill(prime, prime + 1000001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 1000000; j += i)
			{
				prime[j] = false;
			}
		}
	}

	while (t--)
	{
		cin >> m;
		int left = m / 2;
		int right = m / 2;
		set<pii> s;
		while (left >= 2)
		{
			if (prime[left] && prime[right])
			{
				s.insert({left, right});
			}
			left--;
			right++;
		}
		cout << s.size() << '\n';
	}
	return 0;
}
