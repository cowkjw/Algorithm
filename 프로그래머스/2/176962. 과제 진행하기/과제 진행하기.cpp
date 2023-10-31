#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int TimeConverter(string str)
{
	if (str.size() <= 3)
	{
		return stoi(str);
	}

	return (stoi(str.substr(0, 2)) * 60) + stoi(str.substr(3, 2));
}

vector<string> solution(vector<vector<string>> plans) {
	vector<string> answer;
	priority_queue<pair<int, pair<int, string>>>pq;
	stack<pair<int, pair<int, string>>> s;
	for (const auto& plan : plans)
	{
		int start = TimeConverter(plan[1]);
		int remain = TimeConverter(plan[2]);
		pq.push({ -start,{remain,plan[0]} });
	}
	int curTime = 0;
	while (!pq.empty())
	{
		auto cur = pq.top(); // 시작하기로 한 시각
		if (!s.empty())
		{
			auto sCur = s.top();
			s.pop();
			if (-cur.first > curTime)
			{
				pq.push({ -curTime,{sCur.second.first,sCur.second.second} });
				continue;
			}
			else
			{
				s.push({ curTime,{sCur.second.first,sCur.second.second} });
			}
		}
		pq.pop();
		auto next = pq.top(); // 다음 과제
		curTime = -cur.first + cur.second.first; // 현재 시간 갱신
		if (curTime <=- next.first)
		{
			answer.push_back(cur.second.second);
		}
		else
		{
			curTime = -next.first;
			s.push({ -cur.first,{cur.second.first - (-next.first - (-cur.first)),cur.second.second} });
		}
	}

	while (!s.empty())
	{
		answer.push_back(s.top().second.second);
		s.pop();
	}

	return answer;
}