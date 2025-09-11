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



struct Counselor
{
	int days;
	int cost;
};
int dp[1500001]; // i일에 상담을 끝냈을 때의 최대 수익
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<Counselor> arr(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].days >> arr[i].cost;
	}

	for (int i = 1; i <= n; i++)
	{
		// 안했을 때 vs 했을 때
		if (i + arr[i].days <= n + 1) // 상담이 n일을 넘지 않을 때
			dp[i + arr[i].days] = max(dp[i + arr[i].days], dp[i] + arr[i].cost);
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}

	cout << *max_element(dp, dp + n +2);


    return 0;
}