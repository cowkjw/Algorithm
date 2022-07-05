#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, B;
	int time = INT_MAX;
	int minBlock = INT_MAX;
	int maxBlock = 0;
	int ansBlock = 0;
	cin >> N >> M >> B;
	vector<vector<int>> v(N, vector<int>(M));
	// 제거 2초 인벤에서 꺼내서 넣기 1초

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> v[i][j];
			minBlock = min(minBlock, v[i][j]);
			maxBlock = max(maxBlock, v[i][j]);
		}
	}

	for (int block = minBlock; block <= maxBlock; block++)
	{
		int plusTime = 0;
		int minusTime = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int temp = block - v[i][j];
				if (temp > 0)
					plusTime += temp;
				else
					minusTime += -temp;

			}
		}

		if (minusTime + B >= plusTime)
		{
			int ttime = plusTime + (2 * minusTime);

			if (ttime <= time)
			{
				time = ttime;
				ansBlock = block;
			}
		}

		
	}

	cout << time << " " << ansBlock;


	return 0;

}

