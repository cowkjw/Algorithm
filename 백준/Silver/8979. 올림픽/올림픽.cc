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
		if (a.s == b.s) return a.d > b.d;
		else return a.s > b.s;
	}
	return a.g > b.g;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;

	vector<Medal> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int p,a, b, c;
		cin >>p>> a >> b >> c;
		v[i] = Medal{p,a,b,c };
	}
	sort(v.begin(), v.end(), comp);
	auto it = find_if(v.begin(), v.end(), [](Medal tmp) {return tmp.pos == k; });
	cout << it - v.begin();

	return 0;
}
