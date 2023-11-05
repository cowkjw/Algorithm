#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321
int n, m;
vector<string> coins; // 코인 정보
int dp[51][51]; // dp
int vis[51][51]; // 무한 루프 체크
const int dx[]{ 0,1,0,-1 };
const int dy[]{ 1,0,-1,0 };
bool Check(int y,int x) // 범위 체크
{
	return (y >= 0 && x >= 0 && y < n && x < m);
}

int go(int y,int x)
{
	if (!Check(y, x) || coins[y][x] == 'H') return 0; // 종료

	if (vis[y][x]) // 이미 이전에 방문을 해놨는데 다시 방문
	{
		cout << -1;
		exit(0);
	}

	if (dp[y][x]) return dp[y][x]; // 이미 갱신한 곳
	int X = coins[y][x]-'0'; // X 

	vis[y][x] = 1; // 방문 처리
	for (int i = 0; i < 4; i++)
	{
		int nx = X*dx[i] + x;
		int ny = X*dy[i] + y;
		dp[y][x] = max(dp[y][x], go(ny, nx)+1);
	}
	vis[y][x] = 0; // 다시 미방문

	return dp[y][x];
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		coins.push_back(str);
	}

	cout << go(0, 0);

	return 0;
}