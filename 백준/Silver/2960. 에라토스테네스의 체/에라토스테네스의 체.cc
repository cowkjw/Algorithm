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

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>vec(n + 1,1);

	int cnt = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			if (vec[j] == 0) continue;
			vec[j] = 0;
			cnt++;
			if (cnt == m)
			{
				cout << j;
				return 0;
			}
		}
	}
	return 0;
}
