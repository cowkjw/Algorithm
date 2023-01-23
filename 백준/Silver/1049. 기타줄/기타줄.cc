#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int setPrice = INT_MAX;
	int piecePrice = INT_MAX;

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		setPrice = min(setPrice, a);
		piecePrice = min(piecePrice, b);
	}
	int ans = 0;
	while (n > 0)
	{
		if (n > 6)
		{
			if ((piecePrice * 6) > setPrice)
			{
				n = max(n - 6, 0);
				ans += setPrice;
			}
			else
			{
				n -= 1;
				ans += piecePrice;
			}
		}
		else
		{
			if ((piecePrice * n) > setPrice)
			{
				n =0;
				ans += setPrice;
			}
			else
			{
				n -= 1;
				ans += piecePrice;
			}
		}
	}
	cout << ans;

	return 0;
}