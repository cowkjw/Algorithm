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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; i++) cin >> vec[i];
	vector<int>dp(n);
	vector<int> prev(n, -1);
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (vec[i] > vec[j]) // 이전의 수보다 크다
			{
				if (dp[i] < dp[j] + 1) // 길이를 갱신 할 수 있다
				{
					dp[i] = dp[j] + 1;  // 갱신처리하고
					prev[i] = j;  // i번째의 인덱스는 j 인덱스와 연결
				}
			}
		}
	}
	int idx = max_element(dp.begin(), dp.end()) - dp.begin();
	
	vector<int> lis;
	while (idx != -1) 
	{
		lis.push_back(vec[idx]);
		idx = prev[idx];
	}
	reverse(lis.begin(), lis.end());
	cout << lis.size() << "\n";
	for (auto num : lis) cout << num << " ";

	return 0;
}
