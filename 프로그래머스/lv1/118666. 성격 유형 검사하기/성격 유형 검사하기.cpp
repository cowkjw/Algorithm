#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<char, int>, pair<char, int>>> mbti{ {{'R',0}, {'T',0} },{{'C',0}, {'F',0} },{{'J',0}, {'M',0} },{{'A',0}, {'N',0} } };
vector<int> score{ 3,2,1,0,1,2,3 };
string solution(vector<string> survey, vector<int> choices) {
	string answer = "";

	for (int i = 0; i < choices.size(); i++)
	{
		if (choices[i] > 4)
		{
			for_each(mbti.begin(), mbti.end(), [&](pair<pair<char, int>, pair<char, int>>& a) {
				if (survey[i][1] == a.first.first)
				{
					a.first.second += score[choices[i] - 1];
				}
				else if (survey[i][1] == a.second.first)
				{
					a.second.second += score[choices[i] - 1];
				}
				});
		}
		else if (choices[i] < 4)
		{
			for_each(mbti.begin(), mbti.end(), [&](pair<pair<char, int>, pair<char, int>>& a) {
				if (survey[i][0] == a.first.first)
				{
					a.first.second += score[choices[i] - 1];
				}
				else if (survey[i][0] == a.second.first)
				{
					a.second.second += score[choices[i] - 1];
				}
				});
		}
	}

	for (const auto& pType : mbti)
	{
		if (pType.first.second != pType.second.second)
		{
			if (pType.first.second > pType.second.second)
			{
				answer += pType.first.first;
			}
			else
			{
				answer += pType.second.first;
			}
		}
		else
		{
			answer += pType.first.first;
		}
	}

	return answer;
}