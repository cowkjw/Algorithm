#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, m, l;

int main()
{
	cin >> n >> m >> l;

	vector<int> vec(n, 0);

	vec.push_back(0);
	vec.push_back(l);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	int ans = 1001;
	int low = 1, high = l;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int cnt = 0;

		for (int i = 0; i < vec.size()-1; i ++)
		{
			int dist = vec[i + 1] - vec[i];
			if (dist > mid)
			{
				cnt += (dist - 1) / mid;
			}
		}

		if (cnt<=m)
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