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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> t;

	vector<long long> arr(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	long long s = 1, e = 2, ans = 9223372036854775807;
	while (e <= n) 
	{
		long long diff = arr[e] - arr[s];
		if (diff >= t)
		{
			ans = min(ans, diff);
			s++;
			if (s > e)
				e = s;
		}
		else
		{
			e++;
		}
	}
	cout << ans;


	return 0;
}