#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

vector<int> v;
int t, n, m;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int ret = 1e9;

	cin >> n >> m;
	vector<int> v(n);
	vector<int> v2(m);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
	{
		cin >> v2[i];
	}
	sort(v2.begin(), v2.end());
	int a = 0, b = 0;
	for (const auto i : v)
	{
		if (binary_search(v2.begin(), v2.end(), i)) a++;
	}
	a = v.size() - a;
	for (const auto i : v2)
	{
		if (binary_search(v.begin(), v.end(), i)) b++;
	}
	b = v2.size() - b;
	ret = min(ret, a + b);

	cout << ret;
	return 0;
}
