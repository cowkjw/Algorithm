#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
#include <map>
#include <sstream>
using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const int hDx[] = { -2,-2,-1,-1,1,1,2,2 };
const int hDy[] = { -1,1,-2,2,-2,2,-1,1 };

int board[5][5];
unordered_map<int, pii> um;

bool Check()
{
	int cnt = 0;

	// 행 5개
	// 열 5개
	// 대각선 2개

	for (int i = 0; i < 5; i++)
	{
		// 첫번째 행
		bool bingo = true;
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] != -1)
			{
				bingo = false;
				break;
			}
		}

		if (bingo) cnt++;
	}

	for (int i = 0; i < 5; i++)
	{
		// 첫번째 열
		bool bingo = true;
		for (int j = 0; j < 5; j++)
		{
			if (board[j][i] != -1)
			{
				bingo = false;
				break;
			}
		}

		if (bingo) cnt++;
	}

	int r = 0, c = 0;
	bool bingo = true;
	while (r < 5 && c < 5)
	{
		if (board[r++][c++] != -1)
		{
			bingo = false;
			break;
		}
	}
	if (bingo) cnt++;
	r = 0, c = 4;
	bingo = true;
	while (r < 5 && c >=0)
	{
		if (board[r++][c--] != -1)
		{
			bingo = false;
			break;
		}
	}
	if (bingo) cnt++;
	return cnt >= 3;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> board[i][j];
			um[board[i][j]] = { i,j };
		}
	}

	int ans = 0;
	for (int i = 1; i <= 25; i++)
	{
		int num;
		cin >> num;
		if (Check())
		{
			cout << ans;
			return 0;
		}
		ans++;
		board[um[num].first][um[num].second] = -1;
	}

	return 0;
}