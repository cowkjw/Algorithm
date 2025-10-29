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

int Prime(int start,int end)
{
	vector<bool> isPrime(end + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= end; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= end; j += i)
				isPrime[j] = false;
		}
	}

	int cnt = 0;
	for (int i = start+1; i <= end; i++)
		if (isPrime[i]) cnt++;

	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (cin >> n)
	{
		if (n == 0) break;
		cout << Prime(n, 2 * n) << '\n';
	}
	return 0;
}
