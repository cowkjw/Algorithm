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

int n, m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];
	int l = 0;
	int sum = 0;
	int ans = sum;
	for (int r = 0; r < n; r++) 
	{
		sum += vec[r];

		while (sum > m && l <= r) 
		{
			sum -= vec[l];
			l++;
		}

		// 가능한 최대합 갱신
		ans = max(ans, sum);
	}

	cout << ans;

	return 0;
}
