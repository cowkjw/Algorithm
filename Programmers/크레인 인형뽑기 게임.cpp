#include <string>
#include <vector>
#include<stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s;

	for (int i = 0; i < moves.size(); i++)
	{

		int temp = moves[i] - 1;

		for (int j = 0; j < board.size(); j++)
		{
			if (board[j][temp] != 0)
			{
				if (!s.empty() && s.top() == board[j][temp])
				{
					s.pop();
					answer += 2;
					board[j][temp] = 0;
					break;
				}
				else
				{
					s.push(board[j][temp]);
					board[j][temp] = 0;
					break;
				}
			}
		}
	}

	return answer;
}