#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
using namespace std;
#define INF 987654321
const int dx[4]{ 1,-1,0,0 };
const int dy[4]{ 0,0,1,-1 };
const string cmds[4]{ "D","S","L","R" };
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int input, target;
		cin >> input >> target;
		bool vis[10001]{ false, };
		queue<pair<int,string>> q;
		q.push({ input,"" });
		vis[input] = true;
		bool findTarget = false;
		while (!q.empty()&&!findTarget)
		{
			auto cur = q.front().first;
			auto cmd = q.front().second;
			q.pop();

			for (const auto& ch : cmds)
			{
				string nextCmd = cmd + ch;
				int nextNum = 0;
				if (ch == "D")
				{
					nextNum = (2 * cur) % 10000;
				}
				else if (ch == "S")
				{
					nextNum = cur - 1 < 0 ? 9999 : cur - 1;
				}
				else if (ch == "L")
				{
					nextNum = (cur % 1000) * 10 + cur / 1000;
				}
				else
				{
					nextNum = (cur % 10) * 1000 + cur / 10;
				}

				if (!vis[nextNum])
				{
					if (nextNum == target)
					{
						cout << nextCmd + '\n';
						findTarget = true;
						break;
					}
					vis[nextNum] = true;
					q.push({ nextNum,nextCmd });
				}
			}
		}
	}

	return 0;
}
