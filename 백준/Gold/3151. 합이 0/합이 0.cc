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

    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());

    ll ans = 0; 
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll sum = (ll)vec[i] + vec[j];
            int dis1 = lower_bound(vec.begin() + j + 1, vec.end(), -sum) - vec.begin();
            int dis2 = upper_bound(vec.begin() + j + 1, vec.end(), -sum) - vec.begin();
            ans += dis2 - dis1;
        }
    }
    cout << ans;

	return 0;
}
