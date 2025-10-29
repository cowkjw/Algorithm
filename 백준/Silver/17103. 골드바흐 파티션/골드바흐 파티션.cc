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
bool prime[1000001]{ true, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	fill(prime, prime + 1000001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 1000000; j += i)
			{
				prime[j] = false;
			}
		}
	}

	while (t--)
	{
		cin >> m;
		int cnt = 0;

		for (int left = 2; left <= m / 2; left++)
		{
			int right = m - left;
			if (prime[left] && prime[right])
			{
				cnt++;
			}
		}
        cout<<cnt<<'\n';
	}
	return 0;
}
