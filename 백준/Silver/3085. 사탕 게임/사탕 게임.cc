#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
int n,ret=0;
char board[51][51];


void Check()
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = 0; j < n - 1; j++)
		{
			if (board[i][j] == board[i][j + 1]) cnt++;
			else cnt = 1;
			ret = max(ret, cnt);
		}
	}

	for (int j = 0; j < n; j++)
	{
		int cnt = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (board[i + 1][j] == board[i][j]) cnt++;
			else cnt = 1;
			ret = max(ret, cnt);
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			swap(board[i][j], board[i][j + 1]);
			Check();
			swap(board[i][j], board[i][j + 1]);
		}
	}

	for (int j = 0; j< n; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			swap(board[i+1][j], board[i][j]);
			Check();
			swap(board[i+1][j], board[i][j]);
		}
	}

	cout << ret;

	return 0;
}
