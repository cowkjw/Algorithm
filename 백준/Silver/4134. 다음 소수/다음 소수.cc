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
bool isPrime(ll n)
{
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;

	for (ll i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0) return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;

		// n부터 시작해서 소수 찾기
		while (!isPrime(n))
		{
			n++;
		}

		cout << n << '\n';
	}


	return 0;
}
