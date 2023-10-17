#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
int l, c;
vector<char> v;
set<string> s;
int vis[17];

char arr[]{ 'a','e','i','o','u' };

bool FindChar(string& str)
{
	int cnt1 = 0; // 모음
	for (const auto& ch : str)
	{
		for (int i = 0; i < 5; i++)
		{
			if (ch == arr[i]) cnt1++;
		}
	}
	int cnt2 = l-cnt1; // 자음
	if (cnt2 < 2||cnt1 == 0) return false;
	else return true;
}
void go(int idx, int cnt, string str)
{
	if (cnt == l)
	{
		if (FindChar(str))
		{
			cout << str << '\n';
		}
		return;
	}

	for (int i = idx; i < c; i++)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		go(i, cnt + 1, str + v[i]);
		vis[i] = 0;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		char a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	go(0, 0, "");

	return 0;
}
