#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;
// 맥주는 한 박스 들고 출발(20병) 50 미터 갈 때 한병씩
// 편의점에서는 빈 병을 버리고 한 병 살 수 있음 20병을 넘을 수 없음
// 편의점을 나왔을 때도 50미터 전에 1병 마셔야함
int t, n;
pair<int, int> s, l;
vector<pair<int, int>>p;
int vis[101];
int Manhattan(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(b.second - a.second);
}

bool BFS()
{
	queue<pair<int, int>> q;
	q.push(s);

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		if (Manhattan(cur, l) <= 1000)return true;
		for (int i = 0; i < n; i++)
		{
			if (vis[i]) continue;
			if (Manhattan(p[i], cur) <= 1000)
			{
				q.push(p[i]);
				vis[i] = 1;
			}
		}
	}
	return false;
}
int main()
{

	cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> s.first >> s.second;
		p.clear();
		for (int i = 0; i < n; i++)
		{
			pair<int, int> a;
			cin >> a.first >> a.second;
			p.push_back(a);
		}
		cin >> l.first >> l.second;

		if (BFS())
		{
			cout << "happy\n";
		}
		else
		{
			cout << "sad\n";
		}
		fill(vis, vis + 101, 0);
	}
	return 0;
}


