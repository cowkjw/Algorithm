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
#include <sstream>
using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const int hDx[] = { -2,-2,-1,-1,1,1,2,2 };
const int hDy[] = { -1,1,-2,2,-2,2,-1,1 };

int parent[100001];
int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// 문자열 분리 (split)
vector<string> split(string s, char delim)
{
	vector<string> result;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
	{
		if (!item.empty())
		{  // 빈 문자열 제외
			result.push_back(item);
		}
	}

	return result;
}
string trim(string s)
{
	if (s.empty()) return s;

	int start = 0, end = s.length() - 1;
	while (start <= end && isspace(s[start])) start++;
	while (end >= start && isspace(s[end])) end--;

	if (start > end) return "";
	return s.substr(start, end - start + 1);
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	// 벽장 문이 앞 뒤로 열려있는지 확인하고
	// 열려있는 쪽을 닫아서 내 위치를 열어서 이동하거나 그냥 있거나?
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
	int a, b;
	cin >> a >> b;

	dp[a][b] = dp[b][a] = 0;

	cin >> m;
	vector<int> door(m + 1);
	for (int i = 1; i <= m; i++) cin >> door[i];

	for (int i = 1; i <= m; i++)
	{
		vector<vector<int>> newDP(n + 1, vector<int>(n + 1, INF)); // 처리한 후 새로 갱신
		int d = door[i];
		for (int l = 1; l <= n; l++)
		{
			for (int r = 1; r <= n; r++)
			{
				if (dp[l][r] == INF) continue;

				newDP[d][r] = min(newDP[d][r], dp[l][r] + abs(d - l));
				newDP[l][d] = min(newDP[l][d], dp[l][r] + abs(d - r));
			}
		}
		dp = newDP;
	}

	int ans = INF;
	for (int l = 1; l <= n; l++)
	{
		for (int r = 1; r <= n; r++)
		{
			ans = min(ans,dp[l][r]);
		}
	}
	cout << ans;
	return 0;
}