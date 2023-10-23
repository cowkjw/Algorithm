#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int ret = 1e9;
int maxSize;
map<string, int> m;
// 나와의 번호 차이만큼 5의 제곱승으로 피로도 누적 
// 내가 0이고

void go(int cnt, int sum, vector<int> picks, vector<string> minerals, int idx)
{
	if (sum > ret) return;
	if (minerals.size() == cnt||cnt==maxSize)
	{
		ret = min(sum, ret);
		return;
	}

	if (cnt % 5 == 0) // 교체
	{
		for (int i = 0; i < picks.size(); i++)
		{
			if (picks[i] != 0)
			{
				int cost = 1;
				if (m[minerals[cnt]] < i)
				{
					cost = pow(5, abs(m[minerals[cnt]] - i));
				}
				picks[i]--;
				go(cnt + 1, sum + cost, picks, minerals, i);
				picks[i]++;
			}
		}
	}
	else // 그대로 넣음
	{
		int cost = 1;
		if (m[minerals[cnt]] < idx)
		{
			cost = pow(5, abs(m[minerals[cnt]] - idx));
		}
		go(cnt + 1, sum + cost, picks, minerals, idx);
	}
}

int solution(vector<int> picks, vector<string> minerals) {
	int answer = 0;

	m["diamond"] = 0;
	m["iron"] = 1;
	m["stone"] = 2;

	int cnt = 0;
	for (const int i : picks)
	{
		cnt += 1 * i*5;
	}
	maxSize = cnt;
	go(0, 0, picks, minerals, 0);
	answer = ret;
	return answer;
}