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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> m;

	int ans = 0;
	vector<pii> vec;
	for (int i = 1; i <= m; i++)
	{
		int num, s, e;
		cin >> num >> s >> e;
		vec.push_back({ s,e });
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		auto [s, e] = vec[i];

		// 끝나는 시간을 넣어줬으니까 지금 비교하는 시작 시간보다 더 작으면
		// 지금 강의를 들을 수 있는거
		// 아니라면 강의실을 새로 만들어야함
		while (!pq.empty() && pq.top() <= s)
			pq.pop();

		pq.push(e);
		ans = max(ans, (int)pq.size());
	}
	cout << ans;
	return 0;
}
