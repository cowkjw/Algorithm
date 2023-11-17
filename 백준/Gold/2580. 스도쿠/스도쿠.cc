#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

int board[10][10];
int vis[9];
vector<pair<int, int>> v;
bool Check(int y, int x, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[y][i] == num || board[i][x] == num) return false;
    }

    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;

    for (int i = startY; i < startY + 3; i++)
    {
        for (int j = startX; j < startX + 3; j++)
        {
            if (board[i][j] == num) return false;
        }
    }

    return true;
}

bool go(int idx)
{
    if (idx >= v.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << '\n';
        }
        return true;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (Check(v[idx].first, v[idx].second, i))
        {
            board[v[idx].first][v[idx].second] = i;
            if (go(idx + 1)) return true;
            board[v[idx].first][v[idx].second] = 0;
        }
    }
    return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0) v.push_back({ i,j });
		}
	}
	go(0);
	return 0;
}
