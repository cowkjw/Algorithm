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
vector<int> graph[11];
int vis[11];
int student[11];

int ans = INF;
void Back(int idx, int cnt)
{
	bool end = true;
	for (int i = 1; i <= n; i++) // 문제 수
	{
		if (!vis[i])
		{
			end = false;
			break;
		}
	}
	if (end)
	{
		ans = min(ans, cnt);
	}
	for (int i = idx; i < m; i++)
	{
		if (student[i]) continue;
		student[i] = 1;
		for (auto num : graph[i])
		{
			vis[num] ++;
		}
		Back(i + 1, cnt + 1);
		student[i] = 0;
		for (auto num : graph[i])
		{
			vis[num] --;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m; // 문제의 수, 학생의 수

	for (int i = 0; i < m; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			int pro;
			cin >> pro;
			graph[i].push_back(pro);
		}
	}
	Back(0, 0);
	cout << (ans == INF ? -1 : ans);

	return 0;
}
