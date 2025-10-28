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

vector<int> graph[501];
int timeArr[501];
int indegree[501];
int dp[501];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int t, v;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		timeArr[i + 1] = t;
		while (cin >> v)
		{
			if (v == -1)
				break;
			graph[v].push_back(i+1);
			indegree[i + 1]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{

		dp[i] = timeArr[i];
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (auto next : graph[cur])
		{
			if (indegree[next] > 0)
			{
				indegree[next]--;
                dp[next] = max(dp[next], dp[cur] + timeArr[next]);
				if (indegree[next] == 0)
				{
					q.push(next);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << '\n';
	}
	return 0;
}