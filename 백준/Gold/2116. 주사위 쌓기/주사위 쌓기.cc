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
vector<vector<int>> dice(10001, vector<int>(6, 0));
// 0 A 1 B 2 C 3 D 4 E 5 F
int opposite[6] = { 5,3,4,1,2,0};
vector<int> GetSideFaces(int i)
{
	vector<int> side;
	for (int j = 0; j < 6; ++j)
	{
		if (j == i || j == opposite[i]) continue; // 자기 자신, 반대면 제외
		side.push_back(j);
	}
	return side;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 6; j++)
			cin >> dice[i][j];
	}

	int ans = 0;
	for (int j = 0; j < 6; j++)
	{
		// 첫 번째 주사위 올라오는 곳
		int start = dice[1][j];
		auto side = GetSideFaces(j);
		int idx = 2; // 위에 쌓을 주사위
		int curSum = 0;
		for (int num : side)
		{
			curSum = max(dice[1][num], curSum);
		}
		while (idx <= n)
		{
			int newStart = 0;
			// 각 주사위 면을 놓고 돌려가면서 제일 큰 값으로 찾기
			int tmpNum = 0;
			for (int i = 0; i < 6; i++)
			{
				if (dice[idx][i] == start) // 놓을 수 있음
				{
					auto tmpSide = GetSideFaces(i);
					
					for (int tmpIdx : tmpSide) // 옆면 인덱스
					{
						tmpNum = max(dice[idx][tmpIdx], tmpNum);
					}
					newStart = dice[idx][opposite[i]]; // 반대편이 새로운 시작
					break;
				}
			}
			curSum += tmpNum;
			start = newStart;
			idx++;
		}
		ans = max(curSum, ans);
	}
	cout << ans;
	return 0;
}
