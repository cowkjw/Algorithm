#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

int n, m, d;
vector<int> arr;
int ans = 0;
int vis[11];

void Back(int weight)
{
	if (arr.size() == 2)
	{
		ans = max(weight, ans);
		return;
	}

	for (int i = 1; i < arr.size() - 1; i++)
	{
		int val = arr[i];
		int tmpW = arr[i - 1] * arr[i + 1];
		arr.erase(arr.begin() + i);
		Back(weight + tmpW);
		arr.insert(arr.begin() + i, val);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	
	arr.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	Back(0);
	cout << ans;


	return 0;
}
