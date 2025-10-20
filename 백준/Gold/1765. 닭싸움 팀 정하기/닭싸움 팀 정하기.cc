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
using namespace std;
#define INF 987654321


using ll = long long;
using pii = pair<int, int>;

int n, m;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
int parent[2001]; 

int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b) parent[a] = b;
}
vector<int> enemy[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n;
	for (int i = 1; i <= 2 * n; i++)
		parent[i] = i;
	cin >> m;
	int ans = 0;
	for (int i = 0; i < m; i++) 
	{
		char c;
		int a, b;
		cin >> c >> a >> b;

		if (c == 'F')
		{
			Union(a, b); // 친구끼리
		}
		else if (c == 'E') 
		{
			enemy[a].push_back(b);
			enemy[b].push_back(a);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int e : enemy[i])
		{
			for (int e2 : enemy[e])
			{
				Union(i, e2); // 나의 원수의 원수는 나의 친구
			}
		}
	}

	unordered_set<int> s;
	for (int i = 1; i <= n; i++) 
	{
		s.insert(Find(i)); 
	}

	cout << s.size();
	return 0;
}