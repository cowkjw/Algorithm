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

using namespace std;
#define INF 987654321
const int dx[9]{0, -1,-1,0,1,1,1,0,-1 };
const int dy[9]{0, 0,-1,-1,-1,0,1,1,1 };
const int dx2[4]{ -1,1,1,-1 };
const int dy2[4]{ -1,-1,1,1 };

int board[51][51];
int N, M;
bool cloud[51][51];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 행 열에 나머지 연산을 통해서 넘기기
	// 물복사 때 대각선일 때는 나머지 연산 X

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
		}
	}
	cloud[N][1] = cloud[N][2] = cloud[N - 1][1] = cloud[N - 1][2] = true;

	for (int i = 0; i < M; i++)
	{
		int d, s;
		cin >> d >> s;
		bool temp[51][51]{};
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (cloud[y][x])
				{
					// 0 베이스로 만들고 이동 시킨 나머지를 다시 1 베이스로 만들어줌
					// +N을 해주는 이유는 음수일 때 나머지 연산이 제대로 되지 않기 때문
					int nx = ((x - 1 + dx[d] * s) % N + N) % N + 1;
					int ny = ((y - 1 + dy[d] * s) % N + N) % N + 1;

					temp[ny][nx] = true;
					board[ny][nx]++;
				}
			}
		}
		fill(&cloud[0][0], &cloud[0][0] + 51 * 51, false);
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (temp[y][x])
				{
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx2[k];
						int ny = y + dy2[k];
						if (nx < 1 || ny < 1 || nx > N || ny > N)
						{
							continue;
						}
						if (board[ny][nx] > 0)
						{
							board[y][x]++;
						}
					}
				}
			}
		}


		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (board[y][x] >= 2 && !temp[y][x])
				{
					board[y][x] -= 2;
					cloud[y][x] = true;
				}
			}
		}
	}

	int ans = 0;

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			ans += board[y][x];
		}
	}
	cout << ans;
	return 0;
}
