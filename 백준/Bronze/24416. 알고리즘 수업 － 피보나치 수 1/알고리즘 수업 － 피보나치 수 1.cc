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


using ll = long long;
using pii = pair<int, int>;

int n, m;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
int dp[41];
int ans1, ans2;
int Fibo(int x)
{

	if (x == 1 || x == 2)
	{
		ans1++;
		return 1;
	}
	else
	{
		return Fibo(x - 1) + Fibo(x - 2);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	Fibo(n);

	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		ans2++;
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << ans1 << " " << ans2;
	return 0;
}