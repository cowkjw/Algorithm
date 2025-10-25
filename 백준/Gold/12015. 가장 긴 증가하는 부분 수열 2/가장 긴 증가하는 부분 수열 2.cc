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
#include <sstream>
using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	vector<int> lis;
	for (int i = 1; i <= n; i++)
	{
		int num = v[i];
		auto it = lower_bound(lis.begin(), lis.end(), num);
		if (it == lis.end())
		{
			lis.push_back(num);
		}
		else
		{
			*it = num;
		}
	}
	cout << lis.size() << "\n";

	return 0;
}