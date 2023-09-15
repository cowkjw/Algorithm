#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int t, n;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<int> v(6);
		int cnt =0;
			int total = 0;
		for (int i = 0; i < 6; i++)
		{
			cin >> v[i];
			total += v[i];
		}
		while (true)
		{
			cnt++;
			if (total <= n)
			total *= 4;
			else break;
		}

		cout << cnt << '\n';
	}
}