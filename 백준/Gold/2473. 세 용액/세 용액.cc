#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <numeric>
using namespace std;
#define INF 987654321
const int dx[4]{ 1,-1,0,0 };
const int dy[4]{ 0,0,1,-1 };

int main()
{
	int n;
	cin >> n;

	vector<long long> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	// -97 -6 -2 6 98
	// left, right , lower 
	long long minNum = 3000000001;
	long long ans1, ans2, ans3;
	for (int i = 0; i < n - 2; i++)
	{
		int left = i + 1, right = n - 1;
		while (left < right)
		{
			long long tmpSum = vec[left] + vec[right] + vec[i];


			if (abs(minNum) > abs(tmpSum)) // 가장 0과 가까운 거
			{
				minNum = tmpSum;
				ans1 = vec[i], ans2 = vec[left], ans3 = vec[right];
			}

			if (tmpSum < 0)
				left++;
			else
				right--;
		}
	}

	cout << ans1 << " " << ans2 << " " << ans3 << "\n";
	return 0;
}
