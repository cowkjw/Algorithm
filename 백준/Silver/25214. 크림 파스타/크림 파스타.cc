#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<utility>
using namespace std;


int dp[200001];
int main()
{
	int n;
	cin >> n;
	int minNum = 1e10;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		dp[i] = max(dp[i - 1],num-minNum );
		minNum = min(minNum, num);
	}
	for(int i = 1;i<=n;i++)
		cout << dp[i] << " ";
	return 0;
}