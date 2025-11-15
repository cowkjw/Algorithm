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

int vis[251][251];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<string> board;
	int totalWolf = 0, totalSheep = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		board.push_back(str);

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'v') totalWolf++;
			else if (board[i][j] == 'o') totalSheep++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[i][j] || board[i][j] == '#') continue;
			char mark = board[i][j];
			int sheep = 0, wolf = 0;
			if (mark == 'v') wolf++;
			else if(mark == 'o')sheep++;

			vis[i][j] = 1;
			queue<pii> q;
			q.push({ i,j });

			while (!q.empty())
			{
				auto [y, x] = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int ny = dy[dir] + y;
					int nx = dx[dir] + x;
					if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
					if (vis[ny][nx]) continue;
					if (board[ny][nx] == '#') continue;
					if (board[ny][nx] == 'v') wolf++;
					else if (board[ny][nx] == 'o') sheep++;
					vis[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
			if (wolf >= sheep) totalSheep -= sheep;
			else totalWolf -= wolf;
		}
	}
	cout << totalSheep << " " << totalWolf;
	return 0;
}