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

int n, m;

int arr[102][10001];

void compress(int k)
{
	vector<int> tmp(arr[k], arr[k] + n);
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

	for (int i = 0; i < n; i++)
		arr[k][i] = lower_bound(tmp.begin(), tmp.end(), arr[k][i]) - tmp.begin();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) // 우주마다 좌표 압축
	{
		compress(i);
	}

	int ans = 0;
	for (int i = 0; i < m - 1; i++) // i번째 우주
	{
		for (int j = i + 1; j < m; j++) // j번째 우주
		{
			bool flag = true;

			for (int k = 0; k <n; k++) // k번째 행성
			{
				if (arr[i][k] != arr[j][k])
				{
					flag = false;
					break;
				}
			}
			if (flag) ans++;
		}
	}

	cout << ans;
	return 0;
}