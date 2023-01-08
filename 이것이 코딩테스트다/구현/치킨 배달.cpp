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

	if (cnt == m) // 만약 고른 개수가 최대 개수와 같다면
	{
		int tempAns = 0;
		for (int i = 0; i < houses.size(); i++)
		{
			int dist = INF;
			for (int j = 0; j < chickens.size(); j++)
			{
				if (vis[j])
				{
					dist = min(dist, abs(chickens[j].X - houses[i].X) + abs(chickens[j].Y - houses[i].Y)); // 이전 치킨집과 거리 비교
				}
			}
			tempAns += dist;
		}
		ans = min(ans, tempAns); // 답 갱신
		return;
	}

	for (int i = idx; i < chickens.size(); i++) // 치킨집 고르기,파라미터 idx부터 m개까지
	{
		if (vis[i]) continue; // 골랐다면 넘김
		vis[i] = true; // 치킨집 방문처리
		FindDist(cnt + 1, i);
		vis[i] = false; // 치킨집 미방문 처리
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







