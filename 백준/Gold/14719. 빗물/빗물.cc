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

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const int hDx[] = { -2,-2,-1,-1,1,1,2,2 };
const int hDy[] = { -1,1,-2,2,-2,2,-1,1 };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int h, w;
	cin >> h >> w;

	vector<int> blocks(w + 1, 0);
	for (int i = 0; i < w; i++)
		cin >> blocks[i];
	
	int start = blocks[0];

	int ans = 0;

	for (int i = 1; i < w-1; i++)
	{
		int right = *max_element(blocks.begin() + i, blocks.end());

		int val = min(start, right) - blocks[i];
		ans += max(0, val);
		start = max(start, blocks[i]);
	}

	cout << ans;

	return 0;
}