#include <string>
#include <vector>
#include<algorithm>
#define X first 
#define Y second
using namespace std;

bool Build(int type, vector <vector<pair<int, int>>>& board, int x, int y)
{
	if (type)// ��
	{
		if (y == 0) // ���� �ٴڿ� ��ġ
			return false;

		if (board[x][y - 1].second || board[x + 1][y - 1].second)  // ����� ��ġ �Ǿ��ְų�
		{
			return true;
		}
		if (x > 0 && (board[x - 1][y].first && board[x + 1][y].first)) // ���ʿ� ���� ��ġ�Ǿ��ִ��� 
		{
			return true;
		}

	}
	else // ���
	{
		if (y == 0 || board[x][y - 1].second)// �ٴ��̰ų� �ؿ� ��ǥ�� ���
		{
			return true;
		}
		if ((x > 0 && board[x - 1][y].first) || board[x][y].first) // �ؿ� ����̰ų� �ش� ��ǥ�� ���� �ְų�
		{
			return true;
		}
	}
	return false;
}

bool Delete(int x, int y, vector <vector<pair<int, int>>>& board)
{

	for (int i = max(x - 1, 0); i <= x + 1; i++)  // �¿� Ȯ�� , ���� ���� max(x - 1, 0)
	{
		for (int j = y; j <= y + 1; j++) // ������ Ȯ��
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

	vector <vector<pair<int, int>>> board(n + 2, vector<pair<int, int>>(n + 2)); // n+2 ���׸�Ʈ ����

	for (const auto& build : build_frame)
	{

		pair<int, int> pos{ build[0],build[1] }; // ��ǥ
		auto type = build[2]; // ��,��� 
		auto cmd = build[3]; // ���
		if (cmd) // ��ġ�ΰ�
		{
			if (Build(type, board, pos.X, pos.Y))
			{
				if (type) // ��
				{
					board[pos.X][pos.Y].first = 1;
				}
				else
				{
					board[pos.X][pos.Y].second = 1;
				}
			}
		}
		else // ����
		{
			if (type) // ��
			{
				board[pos.X][pos.Y].first = 0;
				if (!Delete(pos.X, pos.Y, board)) // ���� ���ϸ� ���󺹱�
				{
					board[pos.X][pos.Y].first = 1;
				}
			}
			else
			{
				board[pos.X][pos.Y].second = 0;
				if (!Delete(pos.X, pos.Y, board)) // ���� ���ϸ� ���󺹱�
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

			if (board[x][y].second) // ��� ���� �־���
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