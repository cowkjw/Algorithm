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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

	int left = 0, right = *max_element(vec.begin(), vec.end()) - *min_element(vec.begin(), vec.end());

	int ans = right;
	
	while (left <= right)
	{
		int mid = (right + left) / 2;
		int minVal = vec[0];
		int maxVal = vec[0];
		int cnt = 1;
		for (int i = 1; i < n; i++)
		{
			minVal = min(minVal, vec[i]);
			maxVal = max(maxVal, vec[i]);
			if (maxVal - minVal > mid) // 구간이 잘리는 부분 나눴을 때 mid를 만들 수가 없기 때문
			{
				cnt++;
                minVal = vec[i];
				maxVal = vec[i];
			}
		}
		if (cnt<=m)
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
