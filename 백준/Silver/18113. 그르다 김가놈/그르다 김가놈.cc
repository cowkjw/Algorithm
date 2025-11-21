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
#include <cstring>
using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const int dh[] = { -1,1 };

int parent[200001];
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
struct Edge {
	Edge(int u, int v, int w) : u(u), v(v), w(w) {}
	int u, v, w;
};

int dist[1001][1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, m;
	cin >> n >> k >> m;
	vector<ll>len;
	for (int i = 0; i < n; i++)
	{
		ll kim;
		cin >> kim;
		if (kim <= k) continue;
		len.push_back(kim);
	}
	if (len.empty())
	{
		cout << -1;
		return 0;
	}
	ll s = 1, e = *max_element(len.begin(), len.end()) + 1;
	ll ans = -1;
	while (s <= e)
	{
		ll mid = (s + e) / 2;

		int cnt = 0;
		for (int i = 0; i < len.size(); i++)
		{
			ll tmp = len[i];
			if (2 * k > len[i])
			{
				tmp -= k;
			}
			else
			{
				tmp -= 2 * k;
			}

			cnt += tmp / mid;
		}

		if (cnt >= m)
		{
			ans = mid;
			s = mid + 1;
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
	}
	cout << ans;
	return 0;
}