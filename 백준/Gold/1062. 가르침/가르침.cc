#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

vector<char> v{ 'a','n','t','i','c' };
vector<string> strs;
int vis[26], m, n, ret;
int CountWords() {
	int cnt = 0;
	for (const auto& str : strs)
	{
		bool canMake = true;
		for (char c : str)
		{
			if (find(v.begin(), v.end(), c) == v.end()) 
			{
				canMake = false;
				break;
			}
		}
		if (canMake) cnt++;
	}
	return cnt;
}

void go(int idx)
{
	if (v.size() == m)
	{
		ret = max(CountWords(), ret);
		return;
	}

	for (int i = idx; i < 26; i++)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		v.push_back((char)(i + 'a'));
		go(i+1);
		vis[i] = 0;
		v.pop_back();
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	if (m < 5)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		strs.push_back(str);
	}
	vis['a' - 'a'] = 1;
	vis['n' - 'a'] = 1;
	vis['t' - 'a'] = 1;
	vis['i' - 'a'] = 1;
	vis['c' - 'a'] = 1;
	go(0);
	cout << ret;
	return 0;
}
