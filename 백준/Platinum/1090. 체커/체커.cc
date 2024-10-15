#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> ans(n, 1e9);
	vector<pair<int, int>> pos(n, { 0,0 });
	vector<int> xCord,yCord;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		pos[i] = { x,y };
		xCord.push_back(x);
		yCord.push_back(y);
	}

	sort(xCord.begin(), xCord.end());
	sort(yCord.begin(), yCord.end());

	for (int x : xCord)
	{
		for (int y : yCord)
		{
			vector<int> distSum; // 거리 합을 저장할 배열

			for (int i = 0; i < n; i++)
			{
				int dist = abs(x - pos[i].first) + abs(y - pos[i].second);
				distSum.push_back(dist);
			}

			int total_dist = 0;
			sort(distSum.begin(), distSum.end());

			for (int i = 0; i < n; i++)
			{
				total_dist += distSum[i];
				ans[i] = min(ans[i], total_dist);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}