#include <bits/stdc++.h>
using namespace std;

int vis[102][102];
int dx[4] = { 1,0,-1,0 }; // �� �� �� ��
int dy[4] = { 0,1,0,-1 };
int n;
int main()
{


	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> board;
	vector<int> ans;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		board.push_back(str);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j]=='0' || vis[i][j] == 1) // ������ �ƴϰų� �湮�ߴٸ� 
				continue;

			queue<pair<int, int>> q;

			vis[i][j] = 1;
			q.push({ i,j });
			int area = 1; // ����
			cnt++;// ���� üũ

			while (!q.empty())
			{
				auto cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) // ���� ���� ��
						continue;
					if (board[nx][ny] =='0' || vis[nx][ny] == 1)// �� �� ���� �����̰ų� ������ �湮�ߴٸ�
						continue;
					q.push({ nx,ny }); // ����ְ� �����¿� üũ
					vis[nx][ny] = 1; // �湮 üũ
					area++; // ���� üũ
				}
			}

			ans.push_back(area);
		}
	}

	sort(ans.begin(), ans.end());
	cout << cnt << '\n';
	for (auto i : ans)
		cout << i << '\n';



	return 0;

}

