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
bool prime[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	fill(prime, prime + 100001, true);
	int ans = 0;
	prime[0] = prime[1] = false;
	vector<int> Prime;

	for (int i = 2; i * i <= 100000; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 100000; j += i)
			{
				prime[j] = false;
			}
			Prime.push_back(i);
		}
	}

	for (int i = n; i <= m; i++)
	{
		int num = i;
		int tmpCnt = 0;
		for (auto p : Prime)
		{
			while (num % p == 0)
			{
				num /= p;
				tmpCnt++;
			}
		}
		if (num > 1) tmpCnt++;
		if (prime[tmpCnt])
		{
			ans++;
		}
	}
	cout << ans;

	return 0;
}
