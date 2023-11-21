#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

int n;
map<ll, ll> m;
bool comp(pair<ll, ll>& a, pair<ll, ll>& b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll num;
		cin >> num;
		m[num]++;
	}
	vector<pair<ll, ll>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), comp);
	cout << v.front().first;

	return 0;
}
