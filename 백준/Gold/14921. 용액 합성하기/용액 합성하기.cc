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
	cin >> n;

	set<ll> ans;
	vector<ll> liquids(n);
	for (int i = 0; i < n; i++)
	{
		cin >> liquids[i];
	}

	int start = 0, end = n - 1;
	ll sum = 0;
	ll minVal = LL_INF;
	int idx1 = -1, idx2 = -1;
	while (start < end&&end<n)
	{
		sum = liquids[start] + liquids[end];

		if (abs(sum) < minVal)
		{
			minVal = abs(sum);
			idx1 = start;
			idx2 = end;
		}
		if (sum < 0)
		{
			start++;
		}
		else if (sum > 0)
		{
			end--;
		}
		else
		{
			break;
		}
	}
	cout << liquids[idx1] + liquids[idx2];
	return 0;
}