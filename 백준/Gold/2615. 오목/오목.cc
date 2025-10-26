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

int board[21][21];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			int start = board[i][j];
			if (start == 0) continue;
			int cnt, r, c;

			// 오른쪽
			cnt = 0; r = i; c = j;
			while (c <= 19 && board[r][c] == start) { cnt++; c++; }
			if (cnt == 5 &&(j-1<1||board[i][j-1]!=start)
				&&(c>19 || board[i][c]!= start))
			{
				cout << start << '\n';
				cout << i << " " << j;
				return 0;
			}
			
			// 하
			cnt = 0; r = i; c = j;
			while (r <= 19 && board[r][c] == start) { cnt++; r++; }
			if (cnt == 5 &&(i-1<1|| board[i-1][j]!=start)&&
				(r>19|| board[r][j]!=start))
			{
				cout << start << '\n';
				cout << i << " " << j;
				return 0;
			}
			// 대각선 우상, 우하
			cnt = 0; r = i; c = j;
			while (r >= 1 && c <= 19 && board[r][c] == start) { cnt++; r--; c++; }
			if (cnt == 5 &&
				(i + 1 > 19 || j - 1 < 1 || board[i + 1][j - 1] != start) &&
				(r < 1 || c>19 || board[r][c] != start))
			{
				cout << start << '\n';
				cout << i << " " << j;
				return 0;
			}
			
			cnt = 0; r = i; c = j;
			while (r <= 19 && c <= 19 && board[r][c] == start) { cnt++; r++; c++; }
			if (cnt == 5 && (i - 1 < 1 || j - 1 < 1 || board[i - 1][j - 1] != start)
				&& (r>19 || c>19 || board[r][c] != start))
			{
				cout << start  << '\n';
				cout << i << " " << j;
				return 0;
			}
		}
	}
	cout << 0;

	return 0;
}