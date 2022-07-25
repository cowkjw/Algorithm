#include<vector>
#include<queue>
using namespace std;
int dx[4] = { -1,1,0,0 }; //»óÇÏÁÂ¿ì
int dy[4] = { 0,0,-1,1 };
int dist[102][102];

int solution(vector<vector<int> > maps)
{
	int answer = 0;

	queue<pair<int, int>> q;
	int sizeX = maps.size();
	int sizeY = maps[0].size();
	q.push({ 0,0 });
	dist[0][0] = 1;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= sizeX || ny < 0 || ny >= sizeY)
				continue;
			if (maps[nx][ny] != 1 || dist[nx][ny] >= 1)
				continue;
			q.push({ nx,ny });

			dist[nx][ny] = dist[cur.first][cur.second] + 1;


		}
	}
	if (dist[sizeX - 1][sizeY - 1] == 0)
		answer = -1;
	else
		answer = dist[sizeX - 1][sizeY - 1];
	return answer;
}