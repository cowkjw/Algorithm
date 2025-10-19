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
using namespace std;
#define INF 987654321


using ll = long long;
using pii = pair<int, int>;

int n, m;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	string s;
	vector<string>v;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	vector<pii> canPos;
	vector<pii> walls;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == '0')
			{
				canPos.push_back({ i,j });
			}
			else
			{
				walls.push_back({ i,j });
			}

		}
	}
	vector<vector<int>>answer(n, vector<int>(m, 0));
	vector<vector<int>>zeroGroup(n, vector<int>(m, -1));
	vector<int> zeroCount(n * m + 1);
	int groupNum = 1;
	for (int i = 0; i < canPos.size(); i++)
	{
		if (zeroGroup[canPos[i].first][canPos[i].second] != -1) 
			continue;
		queue<pii>q;
		q.push({ canPos[i].first,canPos[i].second });
		zeroGroup[canPos[i].first][canPos[i].second] = groupNum;
		int count = 1;

		while (!q.empty())
		{
			pii cur = q.front();
			q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (v[nx][ny] == '1') continue;
				if (zeroGroup[nx][ny] != -1) continue;
				zeroGroup[nx][ny] = groupNum;
				count++;
				q.push({ nx,ny });
			}
		}
		zeroCount[groupNum] = count;
		groupNum++;
	}

	for (auto& [i, j] : walls) 
	{
		unordered_set<int> chk;
		int sum = 1;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = i + dx[dir];
			int ny = j + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (v[nx][ny] == '1') continue;
			int group = zeroGroup[nx][ny];
			if (group == -1 || !chk.insert(group).second) continue;
			sum += zeroCount[group];
		}
		answer[i][j] = sum % 10;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << answer[i][j];
		}
		cout << "\n";
	}

    return 0;
}