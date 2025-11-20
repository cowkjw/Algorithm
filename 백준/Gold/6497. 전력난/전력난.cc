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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true)
	{

		cin >> m >> n;
		if (m == 0 && n == 0)
			break;
		vector<Edge> graph;
		int total = 0;
		for (int i = 0; i < n; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			graph.emplace_back(x, y, z);
			graph.emplace_back(y, x, z);
			total += z;
		}
		for (int i = 0; i < m; i++) parent[i] = i;
		sort(graph.begin(), graph.end(), [](Edge& a, Edge& b)
			{
				return a.w < b.w;
			});
		int ans = 0;
		for (auto& edge : graph)
		{
			if (Find(edge.u) != Find(edge.v))
			{
				Union(edge.u, edge.v);
				ans += edge.w;
			}
		}
		cout << total - ans << "\n";
	}
	return 0;
}