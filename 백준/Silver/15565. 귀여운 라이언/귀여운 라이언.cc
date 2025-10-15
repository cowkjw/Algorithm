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
using pii = pair<int, int>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> lion;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 1) lion.push_back(i);
	}
	// 라이언 구간 0,4, 6, 9
	// 어피치 구간 1,2,3,5,7,8
	int ans = INF;
	if (lion.size() < k)
	{
		cout << -1;
		return 0;
	}
	for (int lion_idx = 0; lion_idx <= lion.size() - k; lion_idx++)
	{
		int start = lion[lion_idx];
		int end = lion[lion_idx + k - 1];
		ans = min(ans, end - start + 1);
	}
	cout << ans;

    return 0;
}