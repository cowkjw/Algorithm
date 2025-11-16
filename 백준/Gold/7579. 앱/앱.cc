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

const int dx[4] = { 0,0, -1, 1 };
const int dy[4] = { -1,1,0,0 };

int n, m;
int dp[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m; // 실행 중인 앱, 새로운 앱을 여는데 필요한 용량
	// 냅색 문제같은데 
	vector<int> vec(n);
	vector<int> needCost(n);
	for (int i = 0; i < n; i++) cin >> vec[i];
	for (int i = 0; i < n; i++) cin >> needCost[i];
	int sum = accumulate(needCost.begin(), needCost.end(), 0);

	for (int i = 0; i < n; i++)
	{
		int cost = needCost[i]; // 현재 쓰이는 비용
		int mem = vec[i]; // 비우는 용량

		for (int c = sum; c >= cost; c--) // 비용을 줄여가면서 확인
		{
			dp[c] = max(dp[c], dp[c - cost] + mem); // 해당 비용에서 최대로 비우는 용량이 좋은거
		}
	}

	for (int c = 0; c <= sum; c++) 
	{
		if (dp[c] >= m) 
		{
			cout << c;
			return 0;
		}
	}
	return 0;
}
