#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	int n, h;
	cin >> n >> h;
	vector<int> vec(h, 0);

	//석순은 해당 높이에 -1  종유석은 H - 종유석 길이에 +1
	// 그림을 그리고 세로로 세워둔 상태로 생각
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (i% 2 == 0)
		{
			vec[num]--;
			vec[0]++; // 0번째는 전부 ++ 
		}
		else
		{
			vec[h - num]++;
		}
	}
	vector<int>ans(h+1, 0);
	for (int i = 0; i <h; i++)
	{
		ans[i+1] = ans[i] + vec[i];
	}
	ans = vector<int>(ans.begin() + 1, ans.end());
	int ans1 = *min_element(ans.begin(), ans.end());
	int cnt = 0;
	for (const auto ele : ans)
	{
		if (ele == ans1) cnt++;
	}
	cout << ans1 << " " << cnt;

	return 0;
}