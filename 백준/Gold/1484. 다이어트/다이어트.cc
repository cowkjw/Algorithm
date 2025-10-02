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


using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// n^2 -m^2 = 15
	int n = 2, m = 1;
	int g;
	cin >> g;

	vector<int> ans;

	while (true)
	{
		int val = n * n - m * m;
		if (val == g)
		{
			ans.push_back(n);
		}

		if (val > g)
		{
			m++;
		}
		else
		{
			n++;
		}
		if (n * n - (n - 1) * (n - 1) > g)
			break;
	}
	if (ans.size() == 0)
		cout << -1;
	else
	{
		sort(ans.begin(), ans.end());
		for (auto k : ans)
			cout << k << "\n";
	}

    return 0;
}