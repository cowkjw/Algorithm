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

int n;
int blue, white;
vector<vector<int>>vec(128,vector<int>(128));

void Divide(int size,int x,int y)
{

	int cnt = 0;

	bool isSame = true;  // 같은 색인지 체크
	int color = vec[y][x];

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (vec[i][j] != color)
			{
				isSame = false;
				break;
			}
		}
		if (!isSame) break;
	}

	if (isSame)
	{
		if (color == 1) blue++;
		else white++;
		return;  // 같은 색이면 더 나눌 필요 없음
	}

	int half = size / 2;
	Divide(half, x, y);              // 좌상
	Divide(half, x + half, y);        // 우상
	Divide(half, x, y + half);        // 좌하
	Divide(half, x + half, y + half); // 우하
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> vec[i][j];
		}
	}

	Divide(n,0,0);
	cout << white << '\n' << blue;
}