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
vector<string> board;
int vis[101][101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	vector<int> prefix(n + 1);

	for (int i = 1; i <= n; i++)
	{
		prefix[i] = arr[i] + prefix[i - 1];
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;

		cout << prefix[e] - prefix[s-1]<<"\n";
	}
	return 0;
}
