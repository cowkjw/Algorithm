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
using pii = pair<int, int>;
#define INF 987654321

int n, m, d;

int base[4];
int outCnt = 0;

int PlayGame(int cmd)
{
	if (!cmd)
	{
		outCnt++;
		return 0;
	}
	int score = 0;

	for (int i = 3; i >= 1; i--)
	{
		int cur = base[i];
		if (cur)
		{
			int next = i + cmd;
			if (next >= 4)
			{
				score++;
			}
			else
			{
				base[next] = cur;
			}
			base[i] = 0;
		}
	}
	if (cmd == 4)
		score++;
	else
		base[cmd] = 1;
	return score;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n; // 이닝 수

	int ans = 0;
	vector<int> order{ 0,2,3,4,1,5,6,7,8,9 };
	vector<int> players = { 2,3,4,5,6,7,8,9 };
	vector<vector<int>> seq(51, vector<int>(10, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 9; j++)
			cin >> seq[i][j];
	do
	{
		// 1번 선수 4번 타자 고정
		order[4] = 1;
		int pIdx = 0;
		for (int i = 1; i <= 9; i++)
		{
			if (i == 4) continue;
			order[i] = players[pIdx++];
		}

		// 경기 시뮬레이션
		int totalScore = 0;
		int idx = 1; // 현재 타순 인덱스

		for (int inning = 1; inning <= n; inning++)
		{
			fill(base, base + 4, 0);
			outCnt = 0;

			while (true)
			{
				int player = order[idx];
				int result = seq[inning][player];
				totalScore += PlayGame(result);

				if (outCnt == 3)
				{
					idx = (idx % 9) + 1; // 다음 이닝은 다음 타자부터
					break;
				}
				idx = (idx % 9) + 1;
			}
		}

		ans = max(ans, totalScore);

	} while (next_permutation(players.begin(), players.end()));

	cout << ans;

	return 0;
}
