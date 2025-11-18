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

const int dx[4] = { 0,0, -1, 1 };
const int dy[4] = { -1,1,0,0 };

int n, m;
int prefix[100001];
int popcount(int x) 
{
	int c = 0;
	while (x)
	{
		c += (x & 1);  // 마지막 비트가 1이면 카운트
		x >>= 1;       // 오른쪽으로 한 칸 밀기
	}
	return c;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	// n개의 물병을 가지고 있고 한번에 m개의 물병을 옮길 수 있음

	// 물안에 리터수가 같아야함
	// 1,1,1 
	// n개 중 똑같이 담긴 병 2개를 골라서 하나에 담기
	// 2,1
	// 2,1,1
	// 2,2 
	// 4 
	// 개수가 k가 될 때까지
	int cnt = n;
	int ans = 0;
	while (popcount(cnt) > m)
	{
		// 물의 리터수는 1,2,4,8,16 순으로
		// 
		cnt++;
		ans++;
	}
	cout << ans ;
	return 0;
}
