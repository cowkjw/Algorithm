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

int dist[3][100001];
vector<string> board;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int curTime = 0;

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < 2; i++)
	{
		string s; 
		cin >> s;
		board.push_back(s);
	}
	fill(&dist[0][0], &dist[2][100001], -1);
	queue<tuple<int, int, int>> q; // 현재 라인 , 현재 위치, 시간
	q.push({ 0,1,0 });
	dist[0][1] = 0;


	while (!q.empty())
	{
		auto [curLine, curPos, time] = q.front();

		q.pop();
		int nextPos = curPos + 1;
		if (nextPos > n)
		{
			cout << 1;
			return 0;
		}

		if (nextPos > time + 1 && board[curLine][nextPos-1] == '1' && dist[curLine][nextPos] == -1)
		{
			dist[curLine][nextPos] = time + 1;
			q.push({ curLine,nextPos,time + 1 });
		}
		nextPos = curPos - 1;

		if (nextPos > time + 1 && nextPos > 0 && board[curLine][nextPos - 1] == '1' && dist[curLine][nextPos] == -1)
		{
			dist[curLine][nextPos] = time + 1;
			q.push({ curLine,nextPos,time + 1 });
		}

		nextPos = curPos + k;
		int nextLine = (curLine + 1) % 2;
		if (nextPos > n)
		{
			cout << 1;
			return 0;
		}

		if (nextPos > time + 1 && board[nextLine][nextPos - 1] == '1' && dist[nextLine][nextPos] == -1)
		{
			dist[nextLine][nextPos] = time + 1;
			q.push({ nextLine,nextPos,time + 1 });
		}
	}
	cout << 0;
	return 0;
}