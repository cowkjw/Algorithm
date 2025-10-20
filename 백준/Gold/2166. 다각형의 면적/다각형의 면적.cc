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
	vector<pair<double,double>> v;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	double ans = 0.f;
	for (int i = 0; i < n; i++)
	{
		int tmp = (i + 1) % n;
		ans += v[i].first * v[tmp].second - v[i].second * v[tmp].first;
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(ans) / 2.f;

	return 0;
}