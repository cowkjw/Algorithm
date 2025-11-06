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

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };

int n, m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		cin >> n >> m; // m이 k
		vector<ll> vec(n);
		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
		}
		sort(vec.begin(), vec.end());
		int l = 0, r = n - 1;
		ll minDiff = 1e18;

		while (l < r)
		{
			ll sum = vec[l] + vec[r];
			minDiff = min(abs(sum - m), minDiff);
			if (m <sum)
			{
				r--;
			}
			else if (m>=sum)
			{
			    l++;
			}
		}
		 l = 0, r = n - 1;
		 int ans = 0;
		 while (l < r)
		 {
			 ll sum = vec[l] + vec[r];
			 if (minDiff == abs(sum - m)) ans++;
			 if (m < sum)
			 {
				 r--;
			 }
			 else if (m >= sum)
			 {
				 l++;
			 }
		 }
		 cout << ans << '\n';
	}
	return 0;
}
