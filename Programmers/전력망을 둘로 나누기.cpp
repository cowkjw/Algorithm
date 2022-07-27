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
		for (int i = 1; i <= graph.size() - 1; i++)  // ������ 1���� n���� 
		{

			if (graph[cur][i] == 1 && vis[i] == 0) // ������ �Ǿ��ְ� �湮�� ���ߴٸ�
			{
				vis[i] = 1; // �湮 ǥ��
				cnt++; // ���� ��� �� ++
				q.push(i); // ����Ǵ� ��� push
			}

		}
	}
	return cnt;
}

int solution(int n, vector<vector<int>> wires) {
	int answer = 200; // �ִ� ��� ��

	graph.resize(n + 1, vector<int>(n + 1));

	for (int i = 0; i < wires.size(); i++) // ��忡 �� ���� ����
	{
		int s = wires[i][0];
		int e = wires[i][1];
		graph[s][e] = 1;
		graph[e][s] = 1;
	}

	for (int i = 0; i < wires.size(); i++)
	{
		vis = vector<bool>(n + 1); // �ʱ�ȭ (���� ������)
		int s = wires[i][0];
		int e = wires[i][1];

		graph[s][e] = 0; // ���� ���� ����
		graph[e][s] = 0;

		int cnt = BFS(s); // BFS ������ (���� ��ġ �߿�)

		graph[s][e] = 1; // �ٽ� ���� ����
		graph[e][s] = 1;
		int gap = (n - 2 * cnt); // �������� �� ������ ������ ����
		answer = min(abs(gap), answer);


	}

	return answer;
}
