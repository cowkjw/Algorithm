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

	cin >> n;
	stack<int> s;
	while (n--)
	{
		int cmd;
		cin >> cmd;
		switch (cmd)
		{
		case 1:
		{
			int x;
			cin >> x;
			s.push(x);
		}
			break;
		case 2:
			if (s.empty() == false)
			{
				cout << s.top() << "\n";
				s.pop();
			}
			else
				cout << -1 << "\n";
			break;
		case 3:
			cout << s.size() << "\n";
			break;
		case 4:
			cout << s.empty() << "\n";
			break;
		case 5:
			cout << (s.empty() ? -1 : s.top()) << '\n';
			break;
		}
	}

    return 0;
}