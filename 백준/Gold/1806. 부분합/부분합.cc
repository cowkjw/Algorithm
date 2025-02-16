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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n, s;
	cin >> n >> s;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	// 1개도 될 거 같은데
	int start = 0, end = 0;
	int sum = 0;
	int ans = n+1;
	while (start <= end&&end<n)
	{
		sum += vec[end++];
		while (sum >= s)
		{
			ans = min(ans, end - start);
			sum -= vec[start++];  // 왼쪽 포인터(start) 이동
		}
	}

	cout << (ans == n+1 ? 0 : ans);
}