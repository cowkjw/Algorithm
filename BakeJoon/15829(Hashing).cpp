#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string str;
	unsigned long ans = 0;
	unsigned long r = 1;
	int M = 1234567891;
	cin >> N;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		ans += ((str[i] - 96) * r) % M;

		r = (r * 31) % M;
	}

	cout << ans%M;

	return 0;

}

