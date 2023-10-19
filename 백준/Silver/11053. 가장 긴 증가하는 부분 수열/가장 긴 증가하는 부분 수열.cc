#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int n;
vector<int> v;
int dp[1001];
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
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1; // 자기 자신의 길이
		for (int j = 0; j < i; j++) // 0부터 자기 자신 전까지
		{
			if (v[i] > v[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << *max_element(dp,dp+n);

	return 0;
}
