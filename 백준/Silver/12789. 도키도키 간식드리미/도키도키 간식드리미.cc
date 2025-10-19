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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<int> s;
	queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		q.push(a);
	}
	int curOrder = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == curOrder)
		{
			curOrder++;
			while (!s.empty() && s.top() == curOrder)
			{
				s.pop();
				curOrder++;
			}
		}
		else
			s.push(cur);
	}
	if (s.empty())
	{
		cout << "Nice\n";
	}
	else
	{
		cout << "Sad\n";
	}

    return 0;
}