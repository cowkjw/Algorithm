#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
using namespace std;

int n, m, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;  // 5 8 3

	vector<int> vec(n); //  2 4 5 4 6

	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.rbegin(), vec.rend());

	int res = 0;
	int cnt = 0;

	while (m--)
	{
		if (cnt == 3)
		{
			res += vec[1];
			cnt = 0;
		}
		else
		{
			res += vec[0];
			cnt++;
		}
	}

	cout << res;


	return 0;
}







