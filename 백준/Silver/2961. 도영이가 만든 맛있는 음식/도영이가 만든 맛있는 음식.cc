#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <iterator> 
using namespace std;

int n;
int ans = 1e9;
vector<vector<int>> vec;

void Recur(int idx, int sin, int ssen, int use)
{
	if (idx == n)
	{
		if (use == 0) return;
		ans = min(abs(sin - ssen), ans);
		return;
	}

	Recur(idx + 1, sin * vec[idx][0], ssen + vec[idx][1], use + 1);
	Recur(idx + 1, sin, ssen, use);
}

int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		vec.push_back({a,b});
	}
	Recur(0, 1, 0, 0);
	cout << ans;
	return 0;
}