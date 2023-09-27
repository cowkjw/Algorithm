#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, k;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	vector<pair<ll, ll>> pq;
	for (int i = 0; i < n; i++)
	{
		ll a, b;
		cin >> a >> b;
		pq.push_back({ a,b });
	}
	vector<ll> v;
	ll ret = 0;
	for (int i = 0; i < k; i++)
	{
		ll c;
		cin >> c;
		v.push_back(c);
	}
	sort(pq.begin(), pq.end());
	sort(v.begin(), v.end());
	int index = 0;
	priority_queue <ll> temp;
	for (int i = 0; i < k; i++)
	{
		while (index<n&&v[i]>=pq[index].first)
		{ 
			temp.push(pq[index++].second);
		}
		if (!temp.empty())
		{
			ret += temp.top();
			temp.pop();
		}
	}
	cout << ret;

	return 0;
}