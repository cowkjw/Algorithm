#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<ll> v(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.rbegin(), v.rend());
	ll ret = 0;
	for (ll i = 0; i < n; i++)
	{
		ret += max((ll)0,(v[i] - (i + 1 - 1)));
	}
	cout << ret;
	return 0;
}

