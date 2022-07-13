#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int board[102][102];
int t;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


void DecreaseHegiht(int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0)
				continue;
			else
				board[i][j]--;

		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	int count = 0;
	while (t--)
	{
		count++;
		int n;
		int mx = 0; //�ؼ��� ���� �ִ�
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> board[i][j];
				mx = max(mx, board[i][j]);
			}



		if (mx == 0)
		{
			cout << "#" << count << " " << 1 << "\n";
			break;
		}

		int num = 1;// ������ ��
		for (int year = 1; year <= mx; year++)
		{
			DecreaseHegiht(n);
			int temp = 0;
			bool vis[102][102] = {};
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (board[i][j] == 0 || vis[i][j]) // �̹� �湮�߰ų� ���̰� 0�ΰ��
						continue;
					temp++;
					queue<pair<int, int>> q;
					vis[i][j] = 1; // ť�� �ֱ��� �湮ó��
					q.push({ i,j });


					while (!q.empty())
					{

						pair<int, int> cur = q.front();
						q.pop();

						for (int dir = 0; dir < 4; dir++) //�����¿� üũ
						{
							int nx = cur.first + dx[dir]; // x��ǥ
							int ny = cur.second + dy[dir]; // y��ǥ

							if (nx < 0 || nx >= n || ny < 0 || ny >= n) // ���� ���
								continue;
							if (vis[nx][ny] || board[nx][ny] == 0) // �̹� �湮�߰ų� �ؼ����� 0�̶��
								continue;
							vis[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
				}
			}
			num = max(num, temp);
		}
		cout << "#" << count << " " << num << "\n";

	}
}