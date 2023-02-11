#include <bits/stdc++.h>
using namespace std;


int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> graph[i][j];
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (graph[i][k] == 1 && graph[k][j] == 1)
				{
					graph[i][j] = 1;
				}
				
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << '\n';
	}


	return 0;


}
