#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

const int dx[4] = { 0,0, -1, 1 };
const int dy[4] = { -1,1,0,0 };

int n, m;
int prefix[100001];

int vis[20001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> n >> m;
	cin >> str;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		char ch = str[i];
		if (ch == 'P')
		{
			for (int j = max(0,i-m); j <= i + m; j++)
			{
				if (str[j] == 'H' && !vis[j])
				{
					ans++;
					vis[j] = 1;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
