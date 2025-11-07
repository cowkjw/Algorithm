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
const ll MOD = 1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int t;
	cin >> t;

	while (t--)
	{
		priority_queue<ll, vector<ll>, greater<ll>>pq;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			ll m;    
			cin >> m;
			pq.push(m);
		}
		ll ans = 1;
		while (pq.size() > 1)
		{
			ll a = pq.top();
			pq.pop();
			ll b = pq.top();
			pq.pop();
			ll newEnergy = a * b;                // 실제 에너지 값
			pq.push(newEnergy);

			ll cost = ((a % MOD) * (b % MOD)) % MOD;  // 비용 누적용으로 모드 적용
			ans *= cost;
			ans%= MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}
