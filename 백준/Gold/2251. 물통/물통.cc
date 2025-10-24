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
using pii = pair<int, int>;
#define INF 987654321

int n, m, d;

int vis[201][201];
set<int> ans;


void DFS(int a,int b,int c)
{
	if (vis[a][b]) return;
	vis[a][b] = 1;

	if (a == 0) ans.insert(c);

	// 6가지
	// A->B
	int pour = min(a, m - b); // 남아있는 양, 부을 곳에 남은 공간
	DFS(a - pour, b + pour, c);
	// A->C
	pour = min(a, d - c);
	DFS(a - pour, b , c + pour);
	// B->A
	pour = min(b, n - a);
	DFS(a + pour, b - pour, c);
	// B->C
	pour = min(b, d - c);
	DFS(a, b - pour, c+ pour);
	// C->A
	pour = min(c, n - a);
	DFS(a + pour, b , c- pour);
	// C->B
	pour = min(c, m - b);
	DFS(a, b + pour, c- pour);

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> d;

	DFS(0, 0, d);

	for (auto x : ans)
	{
		cout << x << " ";
	}
	return 0;
}
