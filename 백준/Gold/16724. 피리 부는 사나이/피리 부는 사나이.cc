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
using namespace std;
#define INF 987654321


using ll = long long;
using pii = pair<int, int>;

int n, m;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

vector<string> board;
bool finished[1001][1001];
bool visited[1001][1001];
int ans;
int Dir(char c)
{
	if (c == 'L') return 0;
	if (c == 'R') return 1;
	if (c == 'U') return 2;
	return 3; // D
}
void DFS(int x, int y)
{
	visited[x][y] = true;
	int d = Dir(board[x][y]);
	int nx = x + dy[d];
	int ny = y + dx[d];

	if (!visited[nx][ny])
		DFS(nx, ny);
	else if (!finished[nx][ny]) // 방문은 했는데 다시 처리하는 상태
		ans++; // 사이클 발견

	finished[x][y] = true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m;
	board.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}   
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j])
				DFS(i, j);
		}
	}
	cout << ans << "\n";


	return 0;
}