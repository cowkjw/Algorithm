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

ll dp[31];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vector<pii> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i].first >> vec[i].second; // 걸리는 시간 , 마감 기한

	sort(vec.begin(), vec.end(), [](pii& a, pii& b) {

		return a.second < b.second;
		});
	int s = 0, e = 1000001;
	int ans = -1;
	while (s <= e)
	{
		// 하루 24시간
		int mid = (s + e) / 2; // 시작 날짜

		int totalTime = mid;
		bool can = true;
		for (int i = 0; i < n; i++)
		{
			if (vec[i].first + totalTime <= vec[i].second)
			{
				totalTime += vec[i].first;
			}
			else
			{
				can = false;
				e = mid - 1;
				break;
			}
		}
		if (can)
		{
			ans = mid;
			s = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
