#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
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

ll dp[101][21];
int numbers[101];
ll DFS(int cnt,ll num)
{
	if (num > 20 || num < 0)
		return 0;

	if (n - 2 == cnt)
	{
		if (num == numbers[n - 1])
			return 1;
		else 
			return 0;
	}
	

	if (dp[cnt][num] != -1)
		return dp[cnt][num];

	dp[cnt][num] = 0;
	// 중간에 넣을 수 있는 연산자 +,-
	dp[cnt][num] += DFS(cnt + 1, num - numbers[cnt + 1]);
	dp[cnt][num] += DFS(cnt + 1, num + numbers[cnt + 1]);

	return dp[cnt][num];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	fill(&dp[0][0], &dp[100][21], -1);

	cout << DFS(0, numbers[0]);

	return 0;
}
