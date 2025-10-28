#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

int n, m, d;
char arr[11];
ll minVal = 1e18;
ll maxVal = -1;
string minStr;
string maxStr;
int vis[11];
void Back(int cnt, string num,int used)
{
	if (n + 1 == cnt) // 자리 개수
	{
		if (minVal > stoll(num))
		{
			minVal = min(stoll(num), minVal);
			minStr = num;
		}

		if (maxVal < stoll(num))
		{
			maxVal = max(stoll(num), maxVal);
			maxStr = num;
		}

		return;
	}
	vis[used] = 1; // 현재 수를 썼는지 

	if (arr[cnt] == '<')
	{
		for (int i = used + 1; i <= 9; i++)
		{
			if (vis[i]) continue;
			Back(cnt + 1, num + to_string(i), i);
			vis[i] = 0;
		}
	}
	else
	{
	
		for (int i = used - 1; i >= 0; i--)
		{
			if (vis[i]) continue;
			Back(cnt + 1, num + to_string(i), i);
			vis[i] = 0;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 0; i <= 9; i++)
	{
		Back(1, to_string(i), i);
		vis[i] = 0;
	}
	cout << maxStr << "\n" << minStr;
	return 0;
}
