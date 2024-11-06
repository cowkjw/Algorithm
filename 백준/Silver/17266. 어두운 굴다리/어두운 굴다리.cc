#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<utility>
using namespace std;


int n, m;
vector<int> vec;
bool Light(int height)
{
	int start = max(0,vec.front()-height), end = 0;

	for (const auto& pos : vec)
	{
		// 현재 영역의 pos의 start가 이전의 end보다 크다면 return false
		// 아닌 경우는 계속 end를 현재 영역의 end로 갱신
		if (pos - height > end) return false;
		end = pos + height;
	}

	return n <= start + end;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int pos;
		cin >> pos;
		vec.push_back(pos);
	}


	int low = 1, high = 100000;
	int ans = 10000000;
	while (low <= high)
	{
		int mid = (low + high) / 2; // 가로등의 높이

		if (Light(mid))
		{
			ans = min(mid, ans);
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << ans;


	return 0;
}