#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
using namespace std;

int n,k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k; // 25 5

	int ans = 0;
	while (n !=1)
	{
		if (n % k == 0)
			n /= k;
		else
			n--;
		ans++;
	}

	cout << ans;
	return 0;
}







