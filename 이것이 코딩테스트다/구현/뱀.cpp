#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
#define X first 
#define Y second

using namespace std;

int n, ans, apple, L;
vector<pair<int, int>> delta{ {-1,0} ,{0,1},{1,0} ,{0,-1} }; // �� �� �� ��

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int dir = 1; // ������ (��)

	cin >> n;
	vector<vector<int>> board(n + 1, vector<int>(n + 1));

	cin >> apple;

	for (int i = 0; i < apple; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = 1; // ��� ǥ��
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
	int ans = 0; // �ð� ��

	while (true)
	{
		ans++;
		auto headPos = body.front();

		pair<int, int> nextPos({ delta[dir].X + headPos.X,delta[dir].Y + headPos.Y }); // ���� ��ġ

		if (nextPos.X < 1 || nextPos.X > n || nextPos.Y < 1 || nextPos.Y > n) // �� �浹
			break;
		if (board[nextPos.X][nextPos.Y] == 2) // ����� �浹
			break;

		body.push_front(nextPos); // �Ӹ� �߰�

		if (board[nextPos.X][nextPos.Y] == 0) // �þ �Ӹ��� �� ����
		{
			auto tailPos = body.back(); // ���� ������
			body.pop_back();
			board[tailPos.X][tailPos.Y] = 0; // ������ �� ���� 
		}

		board[nextPos.X][nextPos.Y] = 2; // ���� ǥ��

		if (!q.empty())
		{
			auto changeDir = q.front();
			if (changeDir.first == ans)
			{
				q.pop();

				if (changeDir.second == 'L') // ����
				{
					dir = (dir + 3) % 4;
				}
				else // ������
				{
					dir = (dir + 1) % 4;
				}
			}

		}
	}

	cout << ans;

	return 0;
}