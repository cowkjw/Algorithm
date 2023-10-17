#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
int n,ret;
int dp[100001];
vector<int> v;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	dp[0] = v[0];
	ret = v[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		ret = max(ret, dp[i]);
	}
	cout << ret;
	return 0;
}
