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

int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), [](const string& a, const string& b)
		{
			return a.size() < b.size();
		});

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		bool check = false;
		for (int j = i + 1; j < n; j++)
		{
			if (v[j].compare(0, v[i].size(), v[i]) == 0)
			{
				check = true;
				break;
			}
		}
		if (!check)
			ans++;
	}
	cout << ans;
    return 0;
}