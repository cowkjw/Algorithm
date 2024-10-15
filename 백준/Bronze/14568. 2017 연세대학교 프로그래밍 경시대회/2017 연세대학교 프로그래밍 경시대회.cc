#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i <= n; i++) // 남규
	{
		for (int j = 0; j <= n; j++) // 영훈
		{
			for (int k = 0; k <= n; k++) // 택희
			{
				if (i + k + j == n)
				{
					if (i >= j + 2 && k % 2 == 0 && i != 0&&j!=0&&k!=0) ans++;
				}
			}
		}
	}

	cout << ans;

	return 0;
}