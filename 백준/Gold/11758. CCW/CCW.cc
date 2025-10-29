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

int n, m, d;
struct Point
{
	int x, y;
};

int CCW(vector<Point>& Points)
{
	int dir  = (Points[1].x - Points[0].x) * (Points[2].y - Points[0].y)
		- (Points[2].x - Points[0].x) * (Points[1].y - Points[0].y);
	return dir<0 ? -1 : (dir == 0 ? 0 : 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<Point> Points(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> Points[i].x >> Points[i].y;
	}

	int ans = CCW(Points)%10;
	cout << ans;
	return 0;
}
