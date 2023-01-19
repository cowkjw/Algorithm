#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;
int arr[101];

int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		int a, b, c;
		cin >> a >> b >> c;

		for (int i = 0; i < 3; i++)
		{
			int s, e;
			cin >> s >> e;

			for (int j = s; j < e; j++)
			{
				arr[j]++;
			}
		}

		int ans = 0;
		for (int i = 1; i < 101; i++)
		{
			if (arr[i] == 1)
			{
				ans += a;
			}
			else if (arr[i] == 2)
			{
				ans += b*2;
			}
			else if(arr[i]==3)
			{
				ans += c*3;
			}
		}
		cout << ans;
		return 0;
	}