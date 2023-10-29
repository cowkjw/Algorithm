#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
set<set<string>> s;
int vis[9];

bool check(string str, string banned_id)
{
	if (banned_id.size() != str.size())
	{
		return false;
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (banned_id[i] != '*' && str[i] != banned_id[i])
		{
			return false;
		}
	}
	return true;
}

void go(vector<string> user_id, vector<string> banned_id, set<string> v, int idx)
{
	if (idx == banned_id.size())
	{
		s.insert(v);
		return;
	}

	for (int i = 0; i < user_id.size(); i++)
	{
		if (vis[i]) continue;
		if (!check(user_id[i], banned_id[idx])) continue;
		vis[i] = 1;
		v.insert(user_id[i]);
		go(user_id, banned_id, v, idx + 1);
		v.erase(user_id[i]);
		vis[i] = 0;
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	go(user_id, banned_id, {}, 0);
	return s.size();
}
