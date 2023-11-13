#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> Split(string str, string del)
{
	vector<string> ret;
	int pos = -1;
	string token = "";
	while ((pos = str.find(del)) != -1)
	{
		token = str.substr(0, pos);
		ret.push_back(token);
		str.erase(0, pos + del.size());
	}
	ret.push_back(str);
	return ret;
}

int TimeConvert(string t)
{
	return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));
}

vector<int> solution(vector<int> fees, vector<string> records) {

	map<string, int> m;
	map<string, int> feeSumList;
	for (const auto& r : records)
	{
		vector<string> v = Split(r, " ");
		int curTime = TimeConvert(v[0]);
		if (v[2] == "OUT")
		{
			int alreadyTime = m[v[1]]; 
			int dis = curTime - alreadyTime;
			feeSumList[v[1]] += dis; // 누적시간 더하기
			m.erase(v[1]);
		}
		else
		{
			m[v[1]] = curTime;
		}
	}

	if (m.size())
	{
		for (auto& i : m)
		{
			int day = TimeConvert("23:59");
			int alreadyTime = i.second;
			int dis = day - alreadyTime;
			feeSumList[i.first] += dis;
		}
	}
	vector<int> answer;
	for (const auto& f : feeSumList)
	{
		int fee;
		if (f.second > fees[0])  // 누적시간 넘었다면
		{
			fee = fees[1] + ((f.second - fees[0] + fees[2] - 1) / fees[2]) * fees[3];
		}
		else
		{
			fee = fees[1];
		}
		answer.push_back(fee);
	}
	return answer;
}