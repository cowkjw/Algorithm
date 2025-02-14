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
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> tang(n);
	unordered_map<int, int> tmpMap;
	for (int i = 0; i < n; i++)
	{
		cin >> tang[i];
	}

	int left = 0;
	int right = 0;
	int ans = 0;
	while (right< n)
	{
		++tmpMap[tang[right]];

		if (tmpMap.size() <= 2)
		{
			ans = max(ans, n - (left + n - right) + 1);
		}
		else
		{
			--tmpMap[tang[left]];

			if (tmpMap[tang[left]] == 0)
			{
				tmpMap.erase(tang[left]);
			}
			left++;
		}
		right++;
	}

	cout << ans;
	return 0;
}