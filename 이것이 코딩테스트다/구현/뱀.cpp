#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
#define X first 
#define Y second

using namespace std;

int n, ans, apple, L;
vector<pair<int, int>> delta{ {-1,0} ,{0,1},{1,0} ,{0,-1} }; // 북 동 남 서

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int dir = 1; // 오른쪽 (동)

	cin >> n;
	vector<vector<int>> board(n + 1, vector<int>(n + 1));

	cin >> apple;

	for (int i = 0; i < apple; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = 1; // 사과 표시
	}

	cin >> L;

	queue<pair<int, char>> q;

	while (L--)
	{
		int x;
		char c;
		cin >> x >> c;
		q.push({ x,c });
	}

	deque<pair<int, int>> body;
	body.push_back({ 1,1 });
	int ans = 0; // 시간 초

	while (true)
	{
		ans++;
		auto headPos = body.front();

		pair<int, int> nextPos({ delta[dir].X + headPos.X,delta[dir].Y + headPos.Y }); // 다음 위치

		if (nextPos.X < 1 || nextPos.X > n || nextPos.Y < 1 || nextPos.Y > n) // 벽 충돌
			break;
		if (board[nextPos.X][nextPos.Y] == 2) // 몸통과 충돌
			break;

		body.push_front(nextPos); // 머리 추가

		if (board[nextPos.X][nextPos.Y] == 0) // 늘어난 머리가 빈 공간
		{
			auto tailPos = body.back(); // 꼬리 꺼내옴
			body.pop_back();
			board[tailPos.X][tailPos.Y] = 0; // 꼬리는 빈 공간 
		}

		board[nextPos.X][nextPos.Y] = 2; // 몸통 표시

		if (!q.empty())
		{
			auto changeDir = q.front();
			if (changeDir.first == ans)
			{
				q.pop();

				if (changeDir.second == 'L') // 왼쪽
				{
					dir = (dir + 3) % 4;
				}
				else // 오른쪽
				{
					dir = (dir + 1) % 4;
				}
			}

		}
	}

	cout << ans;

	return 0;
}