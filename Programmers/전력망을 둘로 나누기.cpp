#include <string>
#include <vector>

using namespace std;

vector<bool> vis;
vector<vector<int>> graph;

int BFS(int start)
{


	queue<int> q;
	q.push(start);
	vis[start] = 1;
	int cnt = 1;

	while (!q.empty())
	{

		int cur = q.front();
		q.pop();
		for (int i = 1; i <= graph.size() - 1; i++)  // 범위는 1부터 n까지 
		{

			if (graph[cur][i] == 1 && vis[i] == 0) // 연결이 되어있고 방문을 안했다면
			{
				vis[i] = 1; // 방문 표시
				cnt++; // 연결 노드 수 ++
				q.push(i); // 연결되는 노드 push
			}

		}
	}
	return cnt;
}

int solution(int n, vector<vector<int>> wires) {
	int answer = 200; // 최대 노드 수

	graph.resize(n + 1, vector<int>(n + 1));

	for (int i = 0; i < wires.size(); i++) // 노드에 각 간선 연결
	{
		int s = wires[i][0];
		int e = wires[i][1];
		graph[s][e] = 1;
		graph[e][s] = 1;
	}

	for (int i = 0; i < wires.size(); i++)
	{
		vis = vector<bool>(n + 1); // 초기화 (복사 생성자)
		int s = wires[i][0];
		int e = wires[i][1];

		graph[s][e] = 0; // 간선 연결 끊기
		graph[e][s] = 0;

		int cnt = BFS(s); // BFS 돌리기 (시작 위치 중요)

		graph[s][e] = 1; // 다시 간선 연결
		graph[e][s] = 1;
		int gap = (n - 2 * cnt); // 나누어진 두 구역의 간선의 차이
		answer = min(abs(gap), answer);


	}

	return answer;
}
