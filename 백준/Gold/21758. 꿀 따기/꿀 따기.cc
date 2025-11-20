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

const int dx[4] = { 0,0, -1, 1 };
const int dy[4] = { -1,1,0,0 };

int n, m;
vector<string> board;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vector<int> arr(n + 1);
	vector<int> prefix(n + 1);
	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		prefix[i] = prefix[i - 1] + arr[i];
	}

	// 구간 3가지
	// 벌 통 벌

	for (int i = 2; i <= n-1; i++) // 통 위치가 i
	{
		// 2~i
		// i ~ n
		int bee1 = prefix[i] - prefix[1];
		int bee2 = prefix[n-1] - prefix[i-1];
		ans = max(ans, bee1 + bee2);
	}
	// 벌 벌 통
	for (int i = 2; i <= n-1; i++) // 통이 n
	{
		int bee1 = prefix[n] - prefix[1] - arr[i];
		int bee2 = prefix[n] - prefix[i];
		ans = max(ans, bee1 + bee2);
	}
	// 통 벌 벌
	for (int i = 2; i <= n-1; i++)
	{
		// 1~n 구간  1~n-1부터
		// 1~i 구간 1 ~i-1 부터
		int bee1 = prefix[i - 1];
		int bee2 = prefix[n-1] - arr[i];
		ans = max(ans, bee1 + bee2);
	}
	cout << ans;
	return 0;
}
