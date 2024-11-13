#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<utility>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> vec(m);

	for (int i = 0; i < m; i++)
	{
		cin >> vec[i];
	}


	deque<int> de;
	for (int i = 1; i <= n; i++)
	{
		de.push_back(i);
	}
	int ans = 0;

	for (const int num : vec)
	{
		int idx = 0;

		while (num != de[idx]) idx++;

		ans += min(idx, (int)de.size() - idx);

		if (idx <= (int)de.size() - idx) 
		{
			// 왼쪽으로 회전
			rotate(de.begin(), de.begin() + idx, de.end());
		}
		else 
		{
			// 오른쪽으로 회전
			rotate(de.rbegin(), de.rbegin() + (de.size() - idx), de.rend());
		}

		de.pop_front(); // num을 제거
	}
	cout << ans;
	return 0;
}