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


struct Node 
{
	int time = 0; // 걸리는 시간
	int degreeCnt = 0; // 진입 차수
	vector<int> degreeNodes; // 내가 끝나고 나서 진행될 노드들
};
int n;

int dp[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<Node> nodes(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int t, m;
		cin >> t >> m;
		nodes[i].time = t;
		nodes[i].degreeCnt = m;
		for (int j = 0; j < m; j++)
		{
			int a;
			cin >> a;
			nodes[a].degreeNodes.push_back(i); // a가 먼저 진행되고 다음에 진행될 노드들
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (nodes[i].degreeCnt == 0) 
		{ // 선행 작업 없는 것부터 시작
			q.push(i);
			dp[i] = nodes[i].time;
		}
	}

	int ans = 0;
	while (!q.empty()) 
	{
		int cur = q.front();
		q.pop();

		ans = max(ans, dp[cur]); // 현재 작업까지의 시간으로 ans 갱신

		for (int nextNode : nodes[cur].degreeNodes)
		{
			// nextNode 작업은 cur 끝난 후 시작 가능
			dp[nextNode] = max(dp[nextNode], dp[cur] + nodes[nextNode].time);

			if (--nodes[nextNode].degreeCnt == 0)
			{
				q.push(nextNode);
			}
		}
	}

	cout << ans;
	return 0;
}