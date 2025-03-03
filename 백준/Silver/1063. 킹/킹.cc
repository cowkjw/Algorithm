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
#include <unordered_map>
#include <numeric>

using namespace std;
#define INF 987654321
const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
const int dy[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
unordered_map<string, int> dir = { {"R", 0}, {"L", 1}, {"B", 2}, {"T", 3}, {"RT", 4}, {"LT", 5}, {"RB", 6}, {"LB", 7} };

bool isInside(int x, int y)
{
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str1, str2;
	cin >> str1 >> str2;
	int n;
	cin >> n;

	pair<int, int> posKing = { str1[0] - 'A', str1[1] - '1' };
	pair<int, int> posRock = { str2[0] - 'A', str2[1] - '1' };

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		int dirNum = dir[input];
		int nx = posKing.first + dx[dirNum];
		int ny = posKing.second + dy[dirNum];
		if (isInside(nx, ny))
		{
			if (nx == posRock.first && ny == posRock.second)
			{
				int nrx = posRock.first + dx[dirNum];
				int nry = posRock.second + dy[dirNum];
				if (isInside(nrx, nry))
				{
					posRock = { nrx, nry };
					posKing = { nx, ny };
				}
			}
			else
			{
				posKing = { nx, ny };
			}
		}
	}

	cout << char(posKing.first + 'A') << posKing.second + 1 << '\n';
	cout << char(posRock.first + 'A') << posRock.second + 1 << '\n';

	return 0;
}
