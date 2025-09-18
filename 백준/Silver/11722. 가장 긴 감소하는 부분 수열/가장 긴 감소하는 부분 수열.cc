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



int n,t;

int dp[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		dp[i] = 1;
	}



	int ans = 0;
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = n-1; j >i; j--)
		{
			int a = vec[i];
			int b = vec[j];
			if (a > b )
			{
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		ans = max(ans, dp[i]);

	}

	cout << ans;
	return 0;
}