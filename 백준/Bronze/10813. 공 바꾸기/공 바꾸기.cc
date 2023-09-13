#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = i + 1;
	}
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		swap(v[a-1], v[b-1]);
	}
	for (auto i : v)
		cout << i << " ";
	return 0;
}