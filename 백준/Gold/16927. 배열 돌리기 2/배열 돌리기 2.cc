#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
#define INF 987654321

const int dy[]{ -1,-1,0,1,1,1,0,-1 };
const int dx[]{ 0,1,1,1,0,-1,-1,-1 };
const int dr[]{ -1,-1,0,1,1,1,0,-1 }; // 행 이동
const int dc[]{ 0,1,1,1,0,-1,-1,-1 }; // 열 이동
int parent[1001];

int Find(int u)
{
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v)
{
	u = Find(u);
	v = Find(v);
	if (u != v)
		parent[u] = v;
}


int n, m, k;

int board[301][301];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	int layer = min(n, m) / 2;
	for (int i = 1; i <= layer; i++)
	{
		int top = i, left = i;
		int bottom = n - i + 1, right = m - i + 1;

		int perimeter = 2 * ((bottom - top) + (right - left));
		int rotateCount = k % perimeter; 

		while (rotateCount--)
		{
			int tmp = board[top][left];

			// 맨위
			for (int col = left; col < right; col++)
				board[top][col] = board[top][col + 1];
			// 맨 오른쪽
			for (int row = top; row < bottom; row++)
				board[row][right] = board[row + 1][right];
			// 맨 밑
			for (int col = right; col > left; col--)
				board[bottom][col] = board[bottom][col - 1];
			// 맨 왼쪽
			for (int row = bottom; row > top + 1; row--)
				board[row][left] = board[row - 1][left];
			board[top + 1][left] = tmp;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
