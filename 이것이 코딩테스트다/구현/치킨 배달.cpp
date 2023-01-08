#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
#define X first 
#define Y second

using namespace std;


int n, m, ans = INF;
int location;
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
vector<bool> vis(14);

void FindDist(int cnt, int idx)
{

	if (cnt == m) // ���� �� ������ �ִ� ������ ���ٸ�
	{
		int tempAns = 0;
		for (int i = 0; i < houses.size(); i++)
		{
			int dist = INF;
			for (int j = 0; j < chickens.size(); j++)
			{
				if (vis[j])
				{
					dist = min(dist, abs(chickens[j].X - houses[i].X) + abs(chickens[j].Y - houses[i].Y)); // ���� ġŲ���� �Ÿ� ��
				}
			}
			tempAns += dist;
		}
		ans = min(ans, tempAns); // �� ����
		return;
	}

	for (int i = idx; i < chickens.size(); i++) // ġŲ�� ����,�Ķ���� idx���� m������
	{
		if (vis[i]) continue; // ����ٸ� �ѱ�
		vis[i] = true; // ġŲ�� �湮ó��
		FindDist(cnt + 1, i);
		vis[i] = false; // ġŲ�� �̹湮 ó��
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> location;
			if (location == 2)
			{
				chickens.push_back({ i,j });
			}
			else if (location == 1)
			{
				houses.push_back({ i,j });
			}
		}
	}

	FindDist(0, 0);
	cout << ans;

	return 0;
}







