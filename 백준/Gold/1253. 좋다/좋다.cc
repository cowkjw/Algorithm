#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
    sort(v.begin(),v.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int number = v[i];

		int start = 0;
		int end = n-1;

		while (start < end)
		{
			if ((v[start] + v[end]) == number)
			{
				if (start == i) 
					start++;
				else if (end == i)
					end--;
				else
				{
					ans++;
					break;
				}
			}
			else if ((v[start] + v[end]) > number)
			{
				end--;
			}
			else
			{
				start++;
			}

		}
	}
	cout << ans;

	return 0;
}
