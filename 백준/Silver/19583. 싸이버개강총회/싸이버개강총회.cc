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

	unordered_set<string> enteredUsers, exitedUsers;
	string timeAndName;
	int ans = 0;
	while (getline(cin, timeAndName))
	{
		int time = (stoi(timeAndName.substr(0, 2)) * 60) + stoi(timeAndName.substr(3, 2));
		string name = timeAndName.substr(6);

		if (time <= startTime)
		{
			enteredUsers.insert(name);
		}
		else if (time >= endTime && time <= endStreming)
		{
			exitedUsers.insert(name);
		}
	}
	for (const string& user : enteredUsers)
	{
		if (exitedUsers.find(user) != exitedUsers.end())
		{
			ans++;
		}
	}
	cout << ans;

	return 0;
}