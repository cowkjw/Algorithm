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


int n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	int start = 0;
	int end = 0;

	int ans = 0;
	int cnt = 0; // 지금까지 뺀 k의 개수
	while (end < n)
	{
		if (vec[end]%2!=0&&k > 0) // 홀수인데 K가 남아있으면
		{
			k--;
			end++;
			cnt++;
		}
		else if (vec[end] % 2 == 0) // 짝수면
		{
			end++;
		}
		else // 홀수인데 K가 없으면
		{
			while (k == 0) // k가 생길때까지 start를 움직임
			{
				if (vec[start] % 2 != 0)
				{
					k++;
					cnt--;
					cnt = max(0, cnt);
				}
				start++;
			}
		}
		ans = max(ans, end - start -cnt);
	}
	cout << ans;
    return 0;
}