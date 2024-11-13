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
	int n, p;

	cin >> n >> p;

	vector<stack<int>> s(7);

	int ans = 0;
	while (n--)
	{
		int a, b;

		cin >> a >> b;

		while (true)
		{
			if (!s[a].empty() && s[a].top() >= b)  // 큰경우는 다 빼기
			{
				if (s[a].top() == b) break; // 다 빼고 혹시 남아 있는게 나랑 같다면 그냥 멈추기
				s[a].pop();
				ans++;

			}
			else
			{
				s[a].push(b);
				ans++;
				break;
			}
		}
	}

	cout << ans;
	return 0;
}