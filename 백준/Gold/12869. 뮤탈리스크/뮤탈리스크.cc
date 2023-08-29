#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
using namespace std;
const vector<pair<int, int>> dir{ {1,0} ,{-1,0} ,{0,1} ,{0,-1} };
int n, m, res;

int vis[61][61][61];
vector<vector<int>> v{ {9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,9,3},{1,3,9} };
int mutal[4];
struct A
{
	int a, b, c;
};
int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> mutal[i];
	}


	queue<A>q;
	q.push({ mutal[0],mutal[1],mutal[2] });

	while (!q.empty())
	{
		int d = q.front().a;
		int e = q.front().b;
		int f = q.front().c;
		q.pop();
		if (vis[0][0][0]) break;

		for (const auto& i : v)
		{
			int na = max(0, d - i[0]);
			int nb = max(0, e - i[1]);
			int nc = max(0, f - i[2]);

			if (vis[na][nb][nc]) continue;
			vis[na][nb][nc] = vis[d][e][f] + 1;
			q.push({ na,nb,nc });
		}
	}


	cout << vis[0][0][0];
	return 0;
}