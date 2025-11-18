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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> m;

	int cnt = 0;

	
	int idx = 0;
	while (m>0&&idx<n)
	{
		int num = arr[idx];
		int bestIdx = idx; // 현재 놓을 자리
		for (int i = idx+1; i <n && i-idx<=m; i++)
		{
			if (arr[bestIdx] < arr[i])
			{
				bestIdx = i;
			}
		}

		for (int i = bestIdx; i > idx; i--)
		{
			swap(arr[i], arr[i - 1]);
		}
		m -= (bestIdx - idx);
		idx++;
	}
	for (auto i : arr) cout << i << " ";
	return 0;
}
