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
#include <unordered_map>
#include <numeric>

using namespace std;
#define INF 987654321
const int dx[4]{ 1,-1,0,0 };
const int dy[4]{ 0,0,1,-1 };

int n, x;

int main()
{

	cin >> n >> x;
	vector<int>vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	int sum = 0;
	for (int i = 0; i < x; i++)
	{
		sum += vec[i];
	}
	int ans = 0;
	int left = 0, right = x;
	unordered_map<int, int> maxSum;
	if (sum >= ans)
	{
		maxSum[sum]++;
		ans = sum;
	}
	while (right<n)
	{
		sum+=vec[right++]; // 다음 위치로 갈 거니까 그 부분 ++
		sum-=vec[left++]; // 이전 위치 개수 --

		if (sum >= ans)
		{
			maxSum[sum]++;
			ans = sum;
		}
	}

	if (ans == 0)
	{
		cout << "SAD";
		return 0;
	}
	cout << ans <<'\n';
	cout << maxSum[ans];
	
	return 0;
}
