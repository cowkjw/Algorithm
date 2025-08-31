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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	stack<int> s;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;

		while (!s.empty() && s.top() <= h)
		{
			s.pop();
		}
		ans += s.size();
		s.emplace(h);
	}

	cout << ans;
	return 0;
}