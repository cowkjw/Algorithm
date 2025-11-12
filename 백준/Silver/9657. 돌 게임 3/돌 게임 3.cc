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

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;


int dp[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	bool sang = true;
	cin >> n;

	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;
	for (int i = 5; i <= n; i++)
	{
		if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4]) // 이전의 선택처리라면 내가 이번 돌의 개수에 이길 수 있음
			dp[i] = 1;
		else dp[i] = 0;
	}
	if (dp[n]) cout << "SK";
	else cout << "CY";

	

	return 0;
}
