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

struct Homework
{
	int deadline;
	int score;
	bool operator<(const Homework& other) const
	{
		if (deadline ==  other.deadline)
			return score > other.score;
		return deadline < other.deadline;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;
	vector<Homework> v(n);
	for (int i = 0; i < n; i++)
	{
		int d, w;
		cin >> d >> w;
		v[i] = { d,w };
	}
	sort(v.begin(), v.end());
	priority_queue<int,vector<int>,greater<int>>pq;
	for (int i = 0; i < n; i++)
	{
		pq.push(v[i].score);
		if (pq.size() > v[i].deadline)
			pq.pop();
	}
	int ans = 0;
	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
    return 0;
}