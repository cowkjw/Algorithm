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

vector<pair<int, int>> pos;
bool hasFood[101][101];
int vis[101][101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		int r,c;
		cin >> r >> c;
		pos.push_back({ r,c });
		hasFood[r][c] = 1;
	}
	int ans = 0;
	for (auto& p : pos)
	{
		int r = p.first;
		int c = p.second;
		vis[r][c] = 1;
		stack<pii> s;
		s.push({r,c});
		int cnt = 1;
		while (!s.empty())
		{
			auto [y,x] = s.top();
			s.pop();
		
			for (int dir = 0;dir<4;dir++)
			{
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (nx <= 0 || ny <= 0 || ny > n || nx > m) continue;
				if (vis[ny][nx]) continue;
				vis[ny][nx] = 1;
				if (hasFood[ny][nx] == 0) continue;
				s.push({ny,nx});
				cnt++;
			}
		}
		ans = max(cnt, ans);
	}
	cout << ans;
	return 0;
}