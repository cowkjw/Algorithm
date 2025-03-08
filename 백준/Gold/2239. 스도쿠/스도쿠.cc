#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>

using namespace std;
#define INF 987654321

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };

vector<string> board;
bool IsValid(int y, int x, int num)
{
	// 행열 확인 같은 숫자 있는지
	for (int i = 0; i < 9; i++)
	{
		if (board[y][i] - '0' == num) return false;
		if (board[i][x] - '0' == num) return false;
	}
	int boxY = (y / 3) * 3; // 해당 행 
	int boxX = (x / 3) * 3; // 해당 열
	// 3x3 박스 형태 전부 검사
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[boxY + i][boxX + j] - '0' == num) return false;
		}
	}

	return true;
}
bool Back()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (board[y][x] == '0')
			{
				for (int i = 1; i <= 9; i++)
				{
					if (IsValid(y, x, i))
					{
						board[y][x] = i + '0';

						if (Back()) return true;

						board[y][x] = '0';
					}

				}
				return false;
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	for (int i = 0; i < 9; i++)
	{
		cin >> str;
		board.push_back(str);
	}

	// 스도쿠 상하좌우랑 안겹쳐야함

// 행과 열을 각각 넣어보면서 
// 열 0 3 6
// 행 0 3 6 

	if (Back())
	{
		// 해결된 스도쿠 출력
		for (int i = 0; i < 9; i++) 
		{
			cout << board[i] << '\n';
		}
	}

	return 0;
}
