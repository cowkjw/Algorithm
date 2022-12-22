#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
using namespace std;

int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m; // 3 3

	vector<vector<int>> vec(n, vector<int>(m)); //  2 4 5 4 6

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int minNum = 10001;
		for (int j = 0; j < m; j++)
		{
			cin >> vec[i][j];
			minNum = min(vec[i][j], minNum);
		}
		ans = max(minNum, ans);
	}
	cout << ans;

	return 0;
}







