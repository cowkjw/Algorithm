#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int board[101][101];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<vector<int>> chikList;
int n, m;

void go(int start, vector<int> v)
{

	if (v.size() == m)
	{
		chikList.push_back(v);
		return;
	}


	for (int i = start + 1; i < chicken.size(); i++)
	{
			v.push_back(i);
			go(i, v);
			v.pop_back();
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) house.push_back({ i,j });
			else if (board[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	vector<int> v;
	go(-1, v);
	int res = INF;
	for (const auto& li : chikList)
	{

		int answer = 0;
		for (const auto& h : house)
		{
			int minNum = INF;
			for (const auto& i : li)
			{
				int dist = abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second);
				minNum = min(dist, minNum);
			}
			answer += minNum;
		}
		res = min(answer, res);
	}
	cout << res;
}
