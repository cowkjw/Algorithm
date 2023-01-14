#include <string>
#include <vector>

using namespace std;

 int answer;

vector<pair<int,int>> dir {{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};

int solution(vector<vector<int>> board) {


vector<vector<bool>> vis(board.size(),vector<bool>(board.size()));
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 1)
			{
               	if (!vis[i][j])
					answer++;
				vis[i][j] = true;
				for (int k = 0; k < 8; k++)
				{
					int nx = dir[k].first + i;
					int ny = dir[k].second + j;

					if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size()) continue;
					if (vis[nx][ny]) continue;
                    vis[nx][ny] = true;
					answer++;
				}
			}
		}
	}


	return board.size()*board.size() - answer;
}	