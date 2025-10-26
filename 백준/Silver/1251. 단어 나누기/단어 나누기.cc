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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	// 위치 1시작 2
	vector<string> vec;
	for (int i = 1; i < str.size() - 1; i++) 
	{
		for (int j = i + 1; j < str.size(); j++) 
		{
			string a = str.substr(0, i);
			string b = str.substr(i, j - i);
			string c = str.substr(j);

			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			reverse(c.begin(), c.end());

			vec.push_back(a + b + c);
		}
	}
	sort(vec.begin(), vec.end());
	cout << vec[0];
	return 0;
}