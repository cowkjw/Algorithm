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
bool prime[10001]{ true, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	fill(prime, prime + 10001, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <=10000; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 10000; j += i)
			{
				prime[j] = false;
			}
		}
	}

	while (t--)
	{
		cin >> m;
		int left = m / 2;
		int right = m / 2;

		while (left >= 2)
		{
			if (prime[left] && prime[right])
			{
				cout << left << " " << right<<'\n';
				break;
			}
			left--;
			right++;
		}
	}
	return 0;
}
