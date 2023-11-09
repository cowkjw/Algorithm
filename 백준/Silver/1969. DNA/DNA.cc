#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321




int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string ans;
	vector<string> v;
	for (int i = 0; i < n; i++)
	{
		string cur;
		cin >> cur;
		v.push_back(cur);
	}
	for (int i = 0; i < m; i++)
	{
		int arr[4]{};
		for (int j = 0; j < n; j++)
		{
			if (v[j][i] == 'A')
			{
				arr[0]++;
			}
			else if (v[j][i] == 'C')
			{
				arr[1]++;
			}
			else if (v[j][i] == 'G')
			{
				arr[2]++;
			}
			else if (v[j][i] == 'T')
			{
				arr[3]++;
			}
		}
		int idx = 0;
		int ma = 0;
		for (int i = 0; i < 4; i++)
		{
			if (ma < arr[i])
			{
				idx = i;
				ma = arr[i];
			}
		}
		if (idx == 0) ans += 'A';
		else if (idx == 1) ans += 'C';
		else if (idx == 2) ans += 'G';
		else if (idx == 3) ans += 'T';
	}

	int total = 0;
	for (int i = 0; i < m; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (ans[i] != v[j][i]) cnt++;
		}
		total += cnt;
	}
	cout << ans << '\n' << total;
	return 0;
}
