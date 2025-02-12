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
using namespace std;

vector<pair<int, int>> Rotate90(const vector<pair<int, int>>& shape)
{
	vector<pair<int, int>> tmp;

	for (const auto& i : shape)
	{
		tmp.push_back({ -i.second,i.first });
	}
	return tmp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector < vector<pair<int, int>>> vec
	{ {{0,0},{1,0},{2,0},{3,0}}, //ㅡ
		{{0,0},{1,0},{0,1},{1,1}}, // ㅁ
		{{0,0},{0,1},{-1,1},{-1,2}} //ㄴ
	,{{0,0},{0,1},{0,2},{1,2}}, //반대 ㄴ
		{{0,0},{0,1},{0,2},{-1,2}} , 
		{{0,0},{0,1},{1,1}, { 1,2 }},
		{{-1,0},{0,0},{1,0},{0,1}} };

	for (int i = 0; i < 7; i++)
	{
		if (i != 1)
		{
			vector<pair<int, int>> tmp = Rotate90(vec[i]);
			vec.push_back(tmp);
			for (int i = 0; i < 3; i++)
			{
				tmp = Rotate90(tmp);
				vec.push_back(tmp);
			}
		}
	}
	vector<vector<int>> board(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x = j;
			int y = i;
			for (const auto& shape : vec)
			{
				bool can = true;
				int cnt = 0;
				for (const auto& pos : shape)
				{
					int nx = x + pos.first;
					int ny = y + pos.second;

					if (nx < 0 || ny < 0 || nx >= m || ny >= n)
					{
						can = false;
						break;
					}

					cnt += board[ny][nx];
				}
				if (can)
				{
					ans = max(ans, cnt);
				}
			}
		}
	}
	cout << ans;
	return 0;
}