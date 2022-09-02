#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int a, b;
int ans = -1;
void dfs(long long  cur , int cnt)
{
	if (cur == b)
	{
		ans = cnt + 1;
		return;
	}

		if (cur * 2 <= b) dfs(cur * 2, cnt + 1);
		if (cur * 10 + 1 <= b) dfs(cur * 10 + 1, cnt + 1);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> a >> b;

	dfs(a, 0);
	cout << ans;
}