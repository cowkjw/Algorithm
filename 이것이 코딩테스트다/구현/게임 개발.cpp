#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
#define X first 
#define Y second

using namespace std;

vector<pair<int, int>> dir = { {0,-1}, {-1,0},{0,1} ,{1,0} };// �� �� �� ��

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, a, b, d;
	cin >> n >> m;
	cin >> a >> b >> d;

	// ���� x-1 ���� x+1 �� 
	pair<int, int> startPos{ a,b };

	vector<vector<int>> board(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j]; // 1 �ٴ� 0 ����
		}
	}


	int cnt = 0; //ȸ�� Ƚ��
	int ans = 1; // �ڱ� ������ġ
	auto curPos = startPos;
	board[curPos.X][curPos.Y]++;
	pair<int,int> nextPos; // ���� ��ġ 
	while (true)
	{
		d--;
		if (d < 0)
		{
			d = 3;
		}

		nextPos = { (curPos.X + dir[d].X), (curPos.Y + dir[d].Y) }; // �������� �̵��� ��

		if (nextPos.X < 0 || nextPos.X >= n || nextPos.Y < 0 || nextPos.Y >= m)
			continue;
		if (board[nextPos.X][nextPos.Y] == 0) // 0�̶��
		{
			board[nextPos.X][nextPos.Y] = 1;
			curPos = nextPos; // ���� ��ġ�� ����
			ans++; // �̵������Ƿ� ++
			cnt = 0; // ��ȸ�� �ٽ� 0���� 
			continue;
		}
		else
		{
			cnt++;
		}

		if (cnt == 4) // ��� ���� �� ��ȸ
		{
			nextPos = { (curPos.X - dir[d].X), (curPos.Y - dir[d].Y) }; // ��ĭ ��
			if (nextPos.X < 0 || nextPos.X >= n || nextPos.Y < 0 || nextPos.Y >= m)
				continue;
			if (board[nextPos.X][nextPos.Y] == 0)
			{
				curPos = nextPos; // ��ĭ �� �̵�
				cnt = 0;
				continue;
			}
			else
			{
				break;
			}

		}
		
	}

	cout << ans;

	return 0;
}







