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

int n, m;

struct Flower
{
	int smonth, sday;
	int emonth, eday;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector<Flower> flowers;
	flowers.reserve(n);
	for (int i = 0; i < n; i++)
	{
		Flower f;
		cin >> f.smonth >> f.sday >> f.emonth >> f.eday;
		if (f.emonth < 3 || (f.emonth == 3 && f.eday < 1)) 
			continue; // 3월 1일 전에 지는 꽃은 필요 없음
		if (f.smonth > 11 || (f.smonth == 11 && f.sday > 30)) 
			continue; // 11월 30일 이후에 피는 꽃도 필요 없음
		flowers.push_back(f);
	}


	sort(flowers.begin(), flowers.end(), [](const Flower& a, const Flower& b) {

		if (a.smonth == b.smonth) 
		{
			if (a.sday == b.sday)
			{
				if (a.emonth == b.emonth)
					return a.eday > b.eday;
				return a.emonth > b.emonth;
			}
			return a.sday < b.sday;
		}
		return a.smonth < b.smonth;
		});

	int curMonth = 3;
	int curDay = 1;
	int idx = 0;
	int ans = 0;

	while (curMonth < 11 || (curMonth == 11 && curDay <= 30))
	{
		bool found = false;
		int prevMonth = curMonth;
		int prevDay = curDay;

		while (idx < flowers.size() && (flowers[idx].smonth < curMonth) || (flowers[idx].smonth == curMonth && flowers[idx].sday <= curDay))
		{
			Flower f = flowers[idx];
			if (f.emonth > prevMonth || (f.emonth == prevMonth && f.eday > prevDay))
			{
				prevMonth = f.emonth;
				prevDay = f.eday;
				found = true;
			}
			idx++;
		}
		if (!found)
		{
			cout << 0;
			return 0;
		}
		ans++;
		curDay = prevDay;
		curMonth = prevMonth;
	}



	cout << ans;

    return 0;
}