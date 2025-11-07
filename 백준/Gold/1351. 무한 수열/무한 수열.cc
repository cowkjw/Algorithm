#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };


int n, m;
ll num, p, q;
unordered_map<ll, ll> um;


ll DFS(ll a)
{
	if (a == 0) return um[0];
	if (um.find(a) != um.end())
		return um[a];
	um[a] = DFS(a / p) + DFS( a / q);
	return  um[a];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	um[0] = 1;
	cin >> num >> p >> q;

	cout << DFS(num);


	return 0;
}
