#include <bits/stdc++.h>

using namespace std;

int n;
int main(void)
{
	vector<pair<int, int>> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, h;
		cin >> l >> h;
		v.push_back({ l,h });
	}

	sort(v.begin(), v.end());

	int area = 0;
	auto leftBeforeWall = v[0];
	auto rightBeforeWall = v.back();
	for (int i = 1; i < v.size(); i++)
	{

		if (leftBeforeWall.second <= v[i].second)
		{
			area += (v[i].first - leftBeforeWall.first) * leftBeforeWall.second;
			leftBeforeWall = v[i];
		}		
	}

	for (int i = v.size()-1; i >= 0; i--)
	{

		if (rightBeforeWall.second <	 v[i].second)
		{
			area += (rightBeforeWall.first-v[i].first )  * rightBeforeWall.second;
			rightBeforeWall = v[i];
		}
	}



	cout << area+leftBeforeWall.second;
}