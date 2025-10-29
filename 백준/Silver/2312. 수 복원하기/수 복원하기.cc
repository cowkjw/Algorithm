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

int n, m, d;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;
		map<int, int> mp;
		int tmpNum = n;

		for (int i = 2; i * i <= tmpNum; i++)
		{
			while (n % i == 0)
			{
				mp[i]++;
				n /= i;
			}
		}
		if (n > 1) mp[n]++;
		for (auto [num, cnt] : mp)
		{
			cout << num << " " << cnt << "\n";
		}
	}

	return 0;
}
