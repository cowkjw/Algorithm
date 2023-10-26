#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;
int n, m;
int vis[9];
vector<int> v;
vector<int> res;
set<vector<int>> s;
void go(int idx)
{
	if (m == res.size())
	{
		s.insert(res);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		res.push_back(v[i]);
		go(i);
		vis[i] = 0;
		res.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	go(0);

	for (const auto& i : s)
	{
		for (const auto& j : i)
		{
			cout << j << " ";
		}
		cout << '\n';
	}
	return 0;
}


