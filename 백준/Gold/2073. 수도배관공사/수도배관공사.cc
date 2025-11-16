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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int d, p;
	cin >> d >> p;
	// 수도관의 길이가 최대가 되면서 용량이 최소값이
	vector<int> len(p), cap(p);

	for (int i = 0; i < p; i++)
	{
		cin >> len[i] >> cap[i];
	}

	vector<int> dp(d + 1, 0); // 해당 길이의 최대 용량
	dp[0] = (int)1e9; // 시작점은 무한대 용량
	for (int i = 0; i < p; i++)
	{
		int c = cap[i];
		int l = len[i];
		for (int j = d; j >=l; j--)
		{
			if (dp[j - l] > 0) // 만들 수 있는 길이라면
			{
				dp[j] = max(dp[j], min(dp[j - l], c));
			}
		}
	}
	cout << dp[d];


	return 0;
}
