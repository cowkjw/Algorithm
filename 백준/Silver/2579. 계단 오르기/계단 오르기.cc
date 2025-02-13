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
#include <numeric>
using namespace std;
#define INF 987654321

int dp[301];
int main()
{
	int n;
	cin >> n;

	vector<int> staris(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> staris[i];
	}
	dp[0] = staris[0];
	dp[1] = dp[0] + staris[1];
	dp[2] = max(staris[0] + staris[2], staris[1] + staris[2]); // 3층은 1층에서 3층이거나, 2층으로 2계단 오고 3층으로 오는지
	for (int i = 3; i < n; i++)
	{
	// 4번째에 올려면 1,3,4이거나 2,4로 와야한다
		dp[i] = max(dp[i - 2], dp[i - 3] + staris[i - 1]) + staris[i]; // 두개 전에서 왔는지 아니면 3개전에서 2개 뛰어서 올라왔는지
	}

	cout << dp[n - 1];

	return 0;
}
