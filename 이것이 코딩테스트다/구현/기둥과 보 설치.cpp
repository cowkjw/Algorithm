#include <string>
#include <vector>
#include<algorithm>
#define X first 
#define Y second
using namespace std;

bool Build(int type, vector <vector<pair<int, int>>>& board, int x, int y)
{
	if (type)// 보
	{
		if (y == 0) // 보가 바닥에 설치
			return false;

		if (board[x][y - 1].second || board[x + 1][y - 1].second)  // 기둥이 설치 되어있거나
		{
			return true;
		}
		if (x > 0 && (board[x - 1][y].first && board[x + 1][y].first)) // 양쪽에 보가 설치되어있는지 
		{
			return true;
		}

	}
	else // 기둥
	{
		if (y == 0 || board[x][y - 1].second)// 바닥이거나 밑에 좌표가 기둥
		{
			return true;
		}
		if ((x > 0 && board[x - 1][y].first) || board[x][y].first) // 밑에 기둥이거나 해당 좌표에 보가 있거나
		{
			return true;
		}
	}
	return false;
}

bool Delete(int x, int y, vector <vector<pair<int, int>>>& board)
{

	for (int i = max(x - 1, 0); i <= x + 1; i++)  // 좌우 확인 , 음수 방지 max(x - 1, 0)
	{
		for (int j = y; j <= y + 1; j++) // 위에만 확인
		{
			if ((Build(0, board, i, j) == false) && board[i][j].second)
			{
				return false;
			}

			if ((Build(1, board, i, j) == false) && board[i][j].first)
			{
				return false;
			}
		}
	}

	return true;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
	vector<vector<int>> answer;

	vector <vector<pair<int, int>>> board(n + 2, vector<pair<int, int>>(n + 2)); // n+2 세그먼트 방지

	for (const auto& build : build_frame)
	{

		pair<int, int> pos{ build[0],build[1] }; // 좌표
		auto type = build[2]; // 보,기둥 
		auto cmd = build[3]; // 명령
		if (cmd) // 설치인가
		{
			if (Build(type, board, pos.X, pos.Y))
			{
				if (type) // 보
				{
					board[pos.X][pos.Y].first = 1;
				}
				else
				{
					board[pos.X][pos.Y].second = 1;
				}
			}
		}
		else // 삭제
		{
			if (type) // 보
			{
				board[pos.X][pos.Y].first = 0;
				if (!Delete(pos.X, pos.Y, board)) // 삭제 못하면 원상복구
				{
					board[pos.X][pos.Y].first = 1;
				}
			}
			else
			{
				board[pos.X][pos.Y].second = 0;
				if (!Delete(pos.X, pos.Y, board)) // 삭제 못하면 원상복구
				{
					board[pos.X][pos.Y].second = 1;
				}
			}
		}
	}

	for (int x = 0; x < board.size(); x++)
	{
		for (int y = 0; y < board.size(); y++)
		{

			if (board[x][y].second) // 기둥 먼저 넣어줌
			{
				answer.push_back({ x,y, 0 });
			}
			if (board[x][y].first)
			{
				answer.push_back({ x,y, 1 });
			}
		}
	}

	return answer;
}