#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long m, n;

bool Func(const vector<unsigned long long>& vec, unsigned long long time)
{
	unsigned long long cnt = 0;
	for (int i = 0; i < vec.size(); i++)
	{

		cnt += time / vec[i];
	}
	return cnt >= m;
}

int main()
{
	cin >> n >> m;
	vector<unsigned long long> vec(n, 0);
	unsigned long long maxTime(0);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		maxTime = max(maxTime, vec[i]);
	}

	unsigned long long ans = 0;
	unsigned long long low = 1;
	unsigned long long high = 1e19;

	while (low <= high)
	{
		unsigned long long mid = (low + high) / 2;

		if (Func(vec, mid))
		{
			ans = mid;
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
