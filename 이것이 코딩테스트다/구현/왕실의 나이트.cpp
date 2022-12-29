#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define INF 987654321
#define x first
#define y second
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> movePos{ {-2,1},{-2,-1},{2,1},{2,-1},{1,-2},{-1,-2},{1,2},{-1,2} };

	int ans = 0;
	string str;
	cin >> str;
	pair<int, int> pos = { str[0] - 96,str[1] - '0' };

	for (int i = 0; i < 8; i++)
	{
		auto moveX = movePos[i].x + pos.x;
		auto moveY = movePos[i].y + pos.y;

		if (moveX >= 1 && moveX <= 8 && moveY >= 1 && moveY <= 8) // 이동 후 범위 안에 있다면
		{
			ans++;
		}

	}

	cout << ans;

	return 0;
}







