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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string chongTime;
	getline(cin, chongTime);
	int startTime = (stoi(chongTime.substr(0, 2)) * 60) + stoi(chongTime.substr(3, 2));
	int endTime = (stoi(chongTime.substr(6, 2)) * 60) + stoi(chongTime.substr(9, 2));
	int endStreming = (stoi(chongTime.substr(12, 2)) * 60) + stoi(chongTime.substr(15, 2));

	map<string, int> timeMap;
	unordered_set<string> enteredUsers;
	string timeAndName;
	int ans = 0;
	while (getline(cin, timeAndName))
	{
		int time = (stoi(timeAndName.substr(0, 2)) * 60) + stoi(timeAndName.substr(3, 2));
		string name = timeAndName.substr(6);
		if (timeMap.find(name) != timeMap.end())
		{
			if (enteredUsers.find(name) != enteredUsers.end())
			{
				continue; // 이미 들어온 유저는 무시
			}
			int enterTime = timeMap[name];
			// 이미 들어와 있었다면 들어온 시간과 지금 시간 비교
			// 만약 들어온 시간이 시작 시간보다 작거나 같고, 지금 시간이 시작 시간보다 크거나 같다면
			if (enterTime <= startTime)
			{
				if (endTime <= time && time <= endStreming)
				{
					enteredUsers.insert(name);
				
					ans++;
				}
			}
		}
		else
		{
			if (time <= startTime )
			{
				timeMap[name] = time;
			}

		}
	}
	cout << ans;

	return 0;
}