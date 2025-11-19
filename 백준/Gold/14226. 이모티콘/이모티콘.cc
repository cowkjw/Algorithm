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
#include <sstream>
using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

int vis[2001][2001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	queue<pii> q;
	q.push({ 1,0 });
	while (!q.empty())
	{
		auto [screen, clip] = q.front();
		q.pop();

		if (screen == n)
		{
			cout << vis[screen][clip];
			return 0;
		}
		// 3가지
		// 복사
		if (!vis[screen][screen])
		{
			vis[screen][screen] = vis[screen][clip] + 1;
			q.push({ screen ,screen });
		}

		// 붙여넣기
		if (clip > 0 && screen + clip <= 2000 && !vis[screen + clip][clip])
		{
			vis[screen + clip][clip] = vis[screen][clip] + 1;
			q.push({ screen + clip ,clip });
		}

		if (screen - 1 >= 0 && !vis[screen-1][clip])
		{
			vis[screen - 1][clip] = vis[screen][clip] + 1;
			q.push({ screen - 1 ,clip });
		}

	}
	return 0;
}