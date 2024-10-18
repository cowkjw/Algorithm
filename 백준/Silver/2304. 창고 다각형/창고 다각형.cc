#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	vector<int> vec(1001, 0);
	cin >> n;

	int maxHeight = 0;
	int maxX = 0;
	int len = 1;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		vec[x] = y;
		if (maxHeight < y)
		{
			maxHeight = y;

			maxX = x;
		}
		len = max(len, x);

	}


	int ans = 0;
	int curMaxH = 0;
	for (int i = 1; i < maxX; i++)
	{
		curMaxH = max(curMaxH, vec[i]);
		ans += curMaxH;
	}
	curMaxH = 0;
	for (int i = len; i > maxX; i--)
	{
		curMaxH = max(curMaxH, vec[i]);
		ans += curMaxH;
	}

	cout << ans + maxHeight;

	return 0;
}