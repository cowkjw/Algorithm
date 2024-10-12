#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;

bool Func(const vector<int>& vec, int len)
{
	int cnt = 0;
	for (int i = 0; i < vec.size(); i++)
	{

		cnt += vec[i] / len;
	}
	return cnt >= m;
}

int main()
{
	cin >> m >> n;
	vector<int> vec(n, 0);
	int maxLen(0);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		maxLen = max(maxLen, vec[i]);
	}

	int ans = 0;
	int low = 1;
	int high = maxLen;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (Func(vec, mid))
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << ans;
	return 0;

}
