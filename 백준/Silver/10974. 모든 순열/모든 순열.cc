#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;

int vis[9];
int maxCnt = 1;

void Back(vector<int> vec)
{
	if (maxCnt == 0)
		return;
	if (vec.size() == n)
	{
		for (auto num : vec) cout << num << " ";
		cout << '\n';
		maxCnt--;
	}

	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		vec.push_back(i);
		Back(vec);
		vec.pop_back();
		vis[i] = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = n; i >= 2; i--)
	{
		maxCnt *= i;
	}

	Back(vector<int>());
	
	return 0;
}
