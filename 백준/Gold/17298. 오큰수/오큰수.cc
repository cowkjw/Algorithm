#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
int arr[1000001];
int dp[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	stack<int> s;
	fill(dp, dp+1000001, -1);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		while (!s.empty() && arr[s.top()] < arr[i])
		{
			dp[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 1; i <= n; i++) cout << dp[i] << " ";

	return 0;
}
