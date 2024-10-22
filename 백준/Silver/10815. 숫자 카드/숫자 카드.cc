#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	vector<int> vec1(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec1[i];
	}
	cin >> m;
	vector<int> vec2(m);
	
	for (int i = 0; i < m; i++)
	{
		cin >> vec2[i];
	}

	sort(vec1.begin(), vec1.end());

	for (const auto num : vec2)
	{
		int low = 0, high = n- 1;

		bool flag = false;
		while (low <= high)
		{
			int mid = (low + high) / 2;

			if (vec1[mid] == num)
			{
				flag = true;
				break;
			}
			else if (vec1[mid] > num)
			{
				high = mid-1;
			}
			else if(vec1[mid] < num)
			{
				low = mid + 1;
			}
		}

		if (flag) cout << "1 ";
		else cout << "0 ";
	}

	return 0;
}