#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	int ans = 0;
	int sum = 0;
	int start = 1, end = 2;
	sum = start + end;
	while (start < end&&end<=n)
	{
		if (sum == n)
		{
			sum -= start++;
			ans++;
		}
		else if (sum > n)
		{
			sum -= start++;
		}
		else
		{
			end++;
			sum += end;
		}
	}

	cout << ans + 1;

	return 0;
}