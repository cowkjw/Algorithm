#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

int n;
int oper[4]; // + - X /
vector<int> ans{ INT_MIN,INT_MAX };
vector<int> numbers;

void dfs(int cnt, int res)
{
	if (cnt == n - 1)
	{
		ans[0] = max(res, ans[0]);
		ans[1] = min(res, ans[1]);
		return;
	}
	if (oper[0] != 0)
	{
		oper[0]--;
		dfs(cnt + 1, res + numbers[cnt + 1]);
		oper[0]++;
	}
	if (oper[1] != 0)
	{
		oper[1]--;
		dfs(cnt + 1, res - numbers[cnt + 1]);
		oper[1]++;
	}
	if (oper[2] != 0)
	{
		oper[2]--;
		dfs(cnt + 1, res * numbers[cnt + 1]);
		oper[2]++;
	}
	if (oper[3] != 0)
	{
		oper[3]--;
		dfs(cnt + 1, res / numbers[cnt + 1]);
		oper[3]++;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		numbers.push_back(num);
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}

	dfs(0, numbers[0]);

	cout << ans[0] << '\n' << ans[1];

	return 0;
}