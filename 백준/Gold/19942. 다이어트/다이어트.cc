#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <iterator> 
using namespace std;

int n, mp, mf, ms, mv; // 단백질, 지방, 탄수,비타
int ans = 1e9;
vector<vector<int>> vec;
vector<int> arr;
vector<int>ansNum;
void Recur(int idx, int pro, int fat, int car, int vit, int price)
{
	if (mp <= pro && mf <= fat && ms <= car && mv <= vit)
	{
		if (ans > price)
		{
			ans = price;
			ansNum = arr;
		}
		else if (ans == price)
		{
			if (arr < ansNum)
			{
				ansNum = arr;
			}
		}
	}
	if (idx == n)
	{
		return;
	}
	arr.push_back(idx + 1);
	Recur(idx + 1, pro + vec[idx][0], fat + vec[idx][1], car + vec[idx][2], vit + vec[idx][3], +price + vec[idx][4]);
	arr.pop_back();
	Recur(idx + 1, pro, fat, car, vit, price);
}

int main()
{

	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;

		vec.push_back({ a,b,c,d,e });
	}
	Recur(0, 0, 0, 0, 0, 0);
    
	if (ansNum.empty())
	{
		cout << -1;
		return 0;
	}
    cout << ans<<'\n';
    sort(ansNum.begin(), ansNum.end());
	for (const auto i : ansNum)
	{
		cout << i << " ";
	}
	return 0;
}