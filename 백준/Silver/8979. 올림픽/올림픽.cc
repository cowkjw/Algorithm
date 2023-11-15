#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

struct Medal
{
	int pos,g, s, d;
};
int n, k;

bool comp(Medal a, Medal b)
{
	if (a.g == b.g)
	{
		if (a.s == b.s)
		{
			if (a.d == b.d) return a.pos < b.pos;
			else return a.d > b.d;
		}
		else return a.s > b.s;
	}
	return a.g > b.g;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;

	vector<Medal> v(n);
	for (int i = 0; i < n; i++)
	{
		int p,a, b, c;
		cin >>p>> a >> b >> c;
		v[i] = Medal{p,a,b,c };
	}
	sort(v.begin(), v.end(), comp);

	int ret = 1;
	for (int i = 0; i < n; i++)
	{
		
		if (i!=0&&(v[i].g < v[i - 1].g || v[i].s < v[i - 1].s || v[i].d < v[i - 1].d))
		{
			ret++;
		}
		if (v[i].pos == k)
		{
			cout << ret;
			break;
		}
	}

	return 0;
}
