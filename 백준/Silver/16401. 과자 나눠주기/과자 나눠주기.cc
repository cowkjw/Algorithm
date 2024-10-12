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
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());
	int ans = 0;
	int low = 1;
	int high = vec.back();

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
