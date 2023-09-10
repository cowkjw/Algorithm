#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, l;
int board[101][101];
int board2[101][101];
int ret;
int vis[101][101];

void check(int a[101][101])
{
	for (int i = 0; i < n; i++)
	{
		int cnt =1; // 현재 위치부터
		int j;
		for (j = 0; j < n - 1; j++)
		{
			if (a[i][j] == a[i][j + 1]) cnt++;
			else if (a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1; // cnt>=l은 여유 공간까지 생각
			else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1; // 내리막길
			else break;
		}
		if (j == n - 1 && cnt >= 0) ret++;
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			board2[j][i] = board[i][j];
		}
	}
	check(board);
	check(board2);
	cout << ret;

	return 0;
}