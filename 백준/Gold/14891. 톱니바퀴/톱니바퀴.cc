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
const int dx[4]{ 1,-1,0,0 };
const int dy[4]{ 0,0,1,-1 };

struct Rot
{
	int pos;
	int wise;
};
vector<string> vec(5);
int k;
vector<Rot> rots;
// 톱니의 3시는 다음 톱니의 9시
// 톱니의 9시는 이전 톱니의 3시와 맞닿음
void Rotate(int pos, bool cc = true)
{
	//2번 인덱스랑 우측의 톱니의 6번 인덱스랑 맞닿음
	// 반대로 내 6번이 좌측의 2번과 맞닿음
	if (cc)
	{
		rotate(vec[pos].begin(), vec[pos].end() - 1, vec[pos].end());
	}
	else
	{
		rotate(vec[pos].begin(), vec[pos].begin() + 1, vec[pos].end());
	}
}
int main()
{
	for (int i = 1; i <= 4; i++)
	{
		cin >> vec[i];
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int pos, wise;
		cin >> pos >> wise;
		rots.push_back({ pos,wise });
	}

	for (const auto& rot : rots)
	{
		int dir[5]{};

		dir[rot.pos] = rot.wise;
		for (int i = rot.pos; i > 1; i--)
		{
			if (vec[i][6] != vec[i - 1][2])
			{
				dir[i - 1] = -dir[i];
			}
			else
			{
				break;
			}
		}

		for (int i = rot.pos; i < 4; i++)
		{
			if (vec[i][2] != vec[i + 1][6])
			{
				dir[i + 1] = -dir[i];
			}
			else
			{
				break;
			}
		}
		for (int i = 1; i <= 4; i++)
		{
			if (dir[i] == -1) Rotate(i, false);
			else if (dir[i] == 1) Rotate(i);
		}
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (vec[i].front() == '1')
		{
			ans += (int)pow(2, i - 1);
		}
	}
	cout << ans;
	return 0;
}
