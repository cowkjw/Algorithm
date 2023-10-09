#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;
int n;
int board[21][21];
int ret = INF;
int vis[21];
vector<int> star, link;

void Sum()
{
	int s = 0;
	int l = 0;
	for (int i = 0; i < star.size(); i++)
	{
		for (int j = 0; j < star.size(); j++)
		{
			if (i != j)
			{
				s+=board[star[i]][star[j]];
				l+=board[link[i]][link[j]];
			}
		}
	}


	ret = min(abs(s - l), ret);
}

void go(int idx, int cnt)
{
	if (cnt == n / 2)
	{
		link.clear();
		for (int i = 0; i < n; i++)
		{
			if (!vis[i]) link.push_back(i);
		}
		Sum();
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			star.push_back(i);
			go(i + 1, cnt + 1);
			star.pop_back();
			vis[i] = 0;
		}
	}
}

int main(void)
{
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0;j<n;j++)
		{
			cin >> board[i][j];
		}
	}

	go(0, 0);
	cout << ret;
	return 0;
}
