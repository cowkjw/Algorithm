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

vector<int> graph[51];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int a, b;
	while (true)
	{
		cin >> a >> b;
		if (a == -1 && b == -1) 
			break;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> score(n + 1, 0);
	int minScore = INF; // 최소 점수
	for (int i = 1; i <= n; i++)
	{
		vector<int> dist(n + 1, -1);
		queue<int> q; // 회원 번호
		q.push(i);
		dist[i] = 0; // 첫 회원의 점수는 0

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (int next : graph[cur])
			{
				if (dist[next] == -1) // 현재 점수가 없는 경우
				{
					dist[next] = 1 + dist[cur];
					q.push(next);
				}
			}
		}
		int curScore = *max_element(dist.begin()+1, dist.end()); // 현재 회원의 점수 계산
		score[i] = curScore; // 현재 회원의 점수 저장
		minScore = min(minScore, curScore); // 최소 점수 갱신
	}


	vector<int> result;
	for (int i = 1; i <= n; i++)
	{
		if (score[i] == minScore) // 최소 점수와 같은 회원 번호 저장
		{
			result.push_back(i);
		}
	}
	cout << minScore << " " << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}