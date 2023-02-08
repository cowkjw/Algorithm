#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second


using namespace std;

int n;
int ans;
vector<pair<int, int>> v(15);
void dfs(int cnt, int sum)
{
	if (cnt > n)
	{
		return;
	}
	ans = max(sum, ans);
	for (int i = cnt; i < n; i++)
	{
		dfs(i + v[i].first, sum + v[i].second);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}


	dfs(0, 0);

	cout << ans;
	return 0;
}
