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




int truck[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k; // 트럭 수, 다리 길이, 최대 하중

	for (int i = 0; i < n; i++)
		cin >> truck[i];


	queue<int> q;
	int nextTruck = 0;
	int ans = 0;
	int weight = 0;
	while (true)
	{
		ans++;
		if (q.size() == m) // 길이를 유지
		{
			weight -= q.front();
			q.pop();
		}
		if (nextTruck < n && weight + truck[nextTruck] <= k)
		{
			q.push(truck[nextTruck]);
			weight += truck[nextTruck];
			nextTruck++;
		}
		else
		{
			// 길이 유지하기 위해서 무게 0 넣기
			q.push(0);
		}
		if (nextTruck == n && weight == 0)
			break;
	}
	cout << ans;
	return 0;
}