#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>path[101][101]; // 행, 열
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
	int answer = 0;

	for (const auto& route : routes)
	{
		auto sPos(points[route[0] - 1]); // 시작 지점
		int time = 0; // 경로마다 처음부터 초기화
		path[sPos[0]][sPos[1]].push_back(time); // 첫 지점의 시간 기록

		// 경로의 각 점을 차례대로 탐색
		for (int i = 1; i < route.size(); i++) // route[1]부터 탐색
		{
			auto nPos(points[route[i] - 1]); // 다음 지점

			// 현재 지점에서 다음 지점으로 이동
			while (sPos[0] != nPos[0]) // 행 이동
			{
				sPos[0] < nPos[0] ? ++sPos[0] : --sPos[0];
				path[sPos[0]][sPos[1]].push_back(++time); // 시간 기록
			}

			while (sPos[1] != nPos[1]) // 열 이동
			{
				sPos[1] < nPos[1] ? ++sPos[1] : --sPos[1];
				path[sPos[0]][sPos[1]].push_back(++time); // 시간 기록
			}
		}
	}


	for (int y = 0; y < 101; y++)
	{
		for (int x = 0; x < 101; x++)
		{
			if (path[y][x].size()>=2)
			{
				sort(path[y][x].begin(), path[y][x].end());
				path[y][x].push_back(-1);
				int pre = path[y][x][0];
				int cnt = 0;
				for (int i = 1; i < path[y][x].size(); i++)
				{
					int cur = path[y][x][i];
					if (pre == cur) cnt++;
					else
					{
						if (cnt) answer++;
						pre = cur;
						cnt = 0;
					}
				}
			}
		}
	}

	return answer;
}