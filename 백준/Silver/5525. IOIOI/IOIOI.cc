#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s;
	string str;
	cin >> n;
	cin >> s;
	cin >> str;

	int ans = 0;
	for (int i = 0; i < s; i++)
	{
		if (str[i] == 'O') continue;
		int cnt = 0;
		while (str[i + 1] == 'O' && str[i + 2] == 'I')
		{
			cnt++;

			if (cnt == n)
			{
				ans++;
				cnt--;
			}
			i += 2;
		}
	}
	cout << ans;
	return 0;
}
