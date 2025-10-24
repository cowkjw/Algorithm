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
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const int hDx[] = { -2,-2,-1,-1,1,1,2,2 };
const int hDy[] = { -1,1,-2,2,-2,2,-1,1 };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x;
	while (cin >> x) // EOF 
	{
		x *= 10000000;
		cin >> n;
		vector<ll> legos(n);
		for (int i = 0; i < n; i++)
			cin >> legos[i];
		sort(legos.begin(), legos.end());
		int l = 0, r = n - 1;
		while (l < r)
		{
			ll sum = legos[l] + legos[r];
			if (sum == x)
			{
				cout << "yes " << legos[l] << " " << legos[r] << "\n";
				break;
			}
			else if (sum < x)
				l++;
			else
				r--;
		}
		if (l >= r)
		{
			cout << "danger\n";
			continue;
		}
	}
	return 0;
}