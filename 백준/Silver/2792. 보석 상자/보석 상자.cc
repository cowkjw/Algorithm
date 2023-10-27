#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

vector<ll> v;
ll n, m;
bool check(ll mid)
{
	ll num = 0; // 몇 개의 구간으로 나누어지는지 판단하기 위함
	for (const auto& i : v)
	{
		num += i / mid;
		if (i % mid) num++;
	}
	return n >= num; // 학생들에게 나눠지는지
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	ll low = 1, hi = 0, mid;
	v.resize(m);
	for (auto& i : v)
	{
		cin >> i;
		hi = max(i, hi); // 제일 최대부터 시작 하기 위함
	}
	ll ret = 1e18; // 
	while (low <= hi)
	{
		mid = (low + hi) / 2;

		if (check(mid))
		{
			ret = min(mid, ret);
			hi = mid - 1;
		}
		else low = mid + 1;

	}
	cout << ret;

	return 0;
}
