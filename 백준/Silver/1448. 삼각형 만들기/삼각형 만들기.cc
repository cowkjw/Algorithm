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
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	for (int i = n-1; i >= 2; i--)
	{
		int c = v[i];
		int a = v[i - 1];
		int b = v[i - 2];
		if (a + b > c)
		{
			cout << a + b + c;
			return 0;
		}
	}
	cout << -1;
    return 0;
}