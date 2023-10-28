#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

ll att,n, z, lo, hi,mid;

struct Room
{
	ll t, a, h;
};
vector<Room> v;

bool check(ll mid)
{
	ll tmp = mid;// MaxHP
	ll attack = att;// Attack
	for (Room& info : v)
	{
		if (info.t==1)
		{
			ll cnt = info.h / attack;
			if (info.h % attack != 0) cnt++;
			mid -= (cnt-1) * info.a;
			if (mid<= 0) return false;
		}
		else
		{
			attack += info.a; // 공격력 증가
			mid = min(tmp, mid + info.h);
		}
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> att;

	lo = 1;
	hi = 1e18;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(Room{ a,b,c });
	}
	ll ret;
	while (lo <= hi)
	{
		mid = (lo + hi) / (1ll * 2);
		if (check(mid))
		{
			ret = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << ret;

	return 0;
}
