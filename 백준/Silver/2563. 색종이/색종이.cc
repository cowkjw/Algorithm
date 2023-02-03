#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second


using namespace std;



int arr[101][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int ans = n*100;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		
		for (int j = x; j < x + 10; j++)
		{
			for (int k = y; k < y + 10; k++)
			{
				if (arr[j][k] == 1)
				{
					ans--;
				}
				else
				{
					arr[j][k] = 1;
				}
			}
		}
	}
	cout << ans;

	return 0;
}
