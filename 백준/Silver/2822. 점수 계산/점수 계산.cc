#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

vector<pair<int, int>> v;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 1; i <= 8; i++)
	{
		int score;
		cin >> score;
		v.push_back({ score,i });
	}
	sort(v.rbegin(), v.rend());
	priority_queue<int> idx;
	int sum = accumulate(v.begin(), v.begin() + 5, 0, [&idx](int acc, const pair<int, int>& a)
		{
			idx.push(-a.second);
			return acc + a.first;
		});
	cout << sum << '\n';
	while (!idx.empty())
	{
		cout << -idx.top() << " ";
		idx.pop();
	}
	return 0;
}
