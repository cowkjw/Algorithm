#include <bits/stdc++.h>
using namespace std;




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int computerCount, connectNetwork;
	queue<int> q;
	

	cin >> computerCount >> connectNetwork;

	vector<vector<int>> computers(computerCount, vector<int>(computerCount));
	vector<bool> visited(computerCount, false);

	for (int i = 0; i < connectNetwork; i++)
	{
		int c1, c2;
		cin >> c1 >> c2;
		computers[c1 - 1][c2 - 1] = 1;
		computers[c2 - 1][c1 - 1] = 1;
	}
	q.push(1);

	int virus = 0;
	while (!q.empty()) // BFS
	{
		int com = q.front();
		q.pop();
		
		for (int j = 1; j < computerCount; j++)
		{
			if (computers[com - 1][j] == 1&&!visited[j])
			{
				q.push(j + 1);
				visited[j] = true;
				virus++;
			}
		}


	}
	cout << virus;

	return 0;

}

