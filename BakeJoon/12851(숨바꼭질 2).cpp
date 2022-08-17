#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


bool vis[100001];
int n, k,cnt;

int bfs(int start)
{
	queue<pair<int,int>> q;
	q.push({ start,0 });

	int ansTime = 0;
	while (!q.empty())
	{
		
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();
		vis[cur] = true;

		int back = cur - 1;
		int front = cur + 1;
		int jump = 2 * cur;

		if (k == cur&&cnt==0)
		{
		
			cnt++;
			ansTime = time;
			continue;
		}

		if (ansTime == time&&k==cur)
		{
			cnt++;
			continue;
		}


		if (back >= 0 && !vis[back])
		{
			q.push({ back,time + 1 });
		}
		if (front <= 100000 && !vis[front])
		{
			q.push({ front,time + 1 });
		}
		if (jump <= 100000 && !vis[jump])
		{
			q.push({ jump,time + 1 });
		}

	}
	return ansTime;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	int mTime = bfs(n);

	cout << mTime << '\n';
	cout << cnt;
}


