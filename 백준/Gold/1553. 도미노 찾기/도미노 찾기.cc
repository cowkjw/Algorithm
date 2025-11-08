#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m, r;

vector<string> board;
bool used[7][7];
bool vis[8][7];
bool IsValid(int dir, int x, int y)
{
	int ny = y + dy[dir]; // 놓을 위치
	int nx = x + dx[dir]; // 놓을 위치
	if (nx < 0 || ny < 0 || ny >= 8 || nx >= 7) return false;
	if (vis[ny][nx]) return false; // 이미 방문된 칸

	int val1 = board[y][x] - '0';
	int val2 = board[ny][nx] - '0';
	return !used[val1][val2] && !used[val2][val1];
}
int ans;
void DFS( int y, int x)
{
	if (x == 7) { y++; x = 0; }
	if (y == 8) { ans++; return; }

	if (vis[y][x])
	{
		DFS( y, x + 1);
		return;
	}

	for (int j = 0; j < 2; j++)
	{
		if (IsValid( j, x, y))
		{
			int ny = y + dy[j]; 
			int nx = x + dx[j]; 
			int a = board[y][x] - '0';
			int b = board[ny][nx] - '0';
			used[a][b] = used[b][a] = true;
			vis[y][x] = vis[ny][nx] = 1;

			DFS(y, x + 1);

			used[a][b] = used[b][a] = false;
			vis[y][x] = vis[ny][nx] = 0;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 놓을 수 있는지 확인
	// 놓을 수 있다면 다음꺼로 가기
	board.resize(8);
	for (int i = 0; i < 8; i++)
		cin >> board[i];

	DFS( 0, 0);
	cout << ans;
	return 0;
}
