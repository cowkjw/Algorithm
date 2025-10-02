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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int>pq;
	int n, h, t;
	cin >> n >> h >> t;
	for (int i = 0; i < n; i++) {
		int a; 
		cin >> a;
		pq.push(a);
	}
	int cnt = 0; // 뿅망치 사용 횟수
	while (cnt < t && pq.top() >= h && pq.top() > 1) 
	{
		int a = pq.top(); pq.pop();
		pq.push(a / 2);
		cnt++;
	}

	if (pq.top() < h)
	{
		cout << "YES\n" << cnt << "\n";
	}
	else
	{
		cout << "NO\n" << pq.top() << "\n";
	}

    return 0;
}