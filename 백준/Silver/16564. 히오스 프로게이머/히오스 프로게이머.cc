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

	cin >> n >> m;
	vector<ll> team(n);
	for (int i = 0; i < n; i++) cin >> team[i];
	ll s = 1,  e = *max_element(team.begin(), team.end()) + m;
	ll ans = 0;
	while (s <= e)
	{
		ll level = (s + e) / 2;
		ll cnt = m;
		for (int i = 0; i < n; i++)
		{ 
			if (level <= team[i]) continue;
			cnt -= level - team[i];
		}
		if (cnt >= 0)
		{
			ans = max(ans, level);
			s = level + 1;
		}
		else
		{
			e = level - 1;
		}
	}
	cout << ans;
	return 0;
}