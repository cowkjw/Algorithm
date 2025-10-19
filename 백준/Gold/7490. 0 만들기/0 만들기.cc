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
#include <climits>

using namespace std;
using ll = long long;
#define INF 987654321

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };


int parent[1001];
struct Edge
{
	int u, v, cost;
	bool operator<(const Edge& other) const
	{
		return cost < other.cost;
	}
};

int Find(int u)
{
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v)
{
	u = Find(u);
	v = Find(v);
	if (u != v)
		parent[u] = v;
}


int n, m;
vector<string> ans;
void Backtrack(string str, int depth,int num)
{
	if (depth == n)
	{
		if (num == 0)
			ans.push_back(str);
		return;
	}
	Backtrack(str + "+" + to_string(depth + 1), depth + 1, num + (depth+1));
	Backtrack(str + "-" + to_string(depth + 1), depth + 1, num - (depth + 1));
	if ( str.size()>=2)
	{
		if (str[str.size() - 2] == '+')
		{
			Backtrack(str+" " + to_string(depth + 1), depth+1, num - (depth)+(depth * 10 + (depth + 1)));
		}
		else if (str[str.size() - 2] == '-')
		{
			Backtrack(str + " " + to_string(depth + 1), depth+1, num + (depth)+(depth * 10 + (depth + 1)));
		}
		
	}
	else
		Backtrack(str + " " + to_string(depth + 1), depth + 1, depth * 10 + (depth + 1));

}
void Backtrack(string expr, int depth, int total, int last, int sign)
{
	if (depth == n)
	{
		if (total == 0)
			ans.push_back(expr);
		return;
	}

	int next = depth + 1;

	// '+'
	Backtrack(expr + "+" + to_string(next), next, total + next, next, 1);
	// '-'
	Backtrack(expr + "-" + to_string(next), next, total - next, next, -1);
	// ' '
	int newLast = last * 10 + next;
	Backtrack(expr + " " + to_string(next), next, total - sign * last + sign * newLast, newLast, sign);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans.clear();
		Backtrack("1", 1, 1,1,1);
		sort(ans.begin(), ans.end());
		for (const auto& s : ans)
			cout << s << '\n';
		cout << '\n';
	}
		return 0;
}
