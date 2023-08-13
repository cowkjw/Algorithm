#include <bits/stdc++.h>
#define INF -987654321
using namespace std;


int t, n;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		map<string, int> m;
		for (int j = 0; j < n; j++)
		{
			string a, b;
			cin >> a >> b;
			m[b]++;
		}
		long long answer =1;
		for (const auto& i : m)
		{
			answer *=(long long)i.second+1;
		}
		cout << answer - 1 << '\n';
	}



	return 0;
}