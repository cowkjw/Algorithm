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

	cin >> n >> m; // m이 딱 맞춰야하는 무게
	// m은 10억까지 int로 가능

	vector<ll> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		if (vec[i] == m)
		{
			cout << 1;
			return 0;
		}
	}
	// 2개 고르고 나머지 1개 고르기
	// 구간을 나누기 특정 수부터 해서 양쪽으로?
	sort(vec.begin(), vec.end());
	int l = 0, r = n - 1;

	while (l < r)
	{
		// 최대 3개니까 
		if (vec[l] == m)
		{
			cout << 1;
			return 0;
		}
		else if (vec[r] == m)
		{
			cout << 1;
			return 0;
		}
		else if (vec[r] + vec[l] == m)
		{
			cout << 1;
			return 0;
		}
		else
		{
			ll sum = (ll)m - (vec[r] + vec[l]);
			auto it = lower_bound(vec.begin(), vec.begin() + l, sum);
			if (it != vec.begin() + l && *it == sum)
			{
				cout << 1;
				return 0;
			}
			it = lower_bound(vec.begin()+r+1, vec.end(), sum);
			if (it != vec.begin() + r+1 && *it == sum)
			{
				cout << 1;
				return 0;
			}
		}
		ll sum = vec[r] + vec[l];
		if (sum < (ll)m)
		{
			l++;
		}
		else
		{
			r--;
		}
	}

	cout << 0;
	return 0;
}
