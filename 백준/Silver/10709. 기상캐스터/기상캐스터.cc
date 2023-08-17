#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int board[101][101];
int n, c;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n>>c;


	for (int h = 0; h < n; h++)
	{
		int prevCloud = -1;
		for (int w = 0; w < c;w++)
		{
			char a;
			cin >> a;
			if (a == 'c')
			{
				prevCloud = w;
				board[h][w] = 0;
				continue;
			}

			if (prevCloud != -1)
			{
			    board[h][w] = w - prevCloud;
			}
			else
			{
				board[h][w] =-1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}