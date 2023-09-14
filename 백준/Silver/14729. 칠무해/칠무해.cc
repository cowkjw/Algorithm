#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	priority_queue<double, vector<double>, greater<double>>pq;
	for (int i = 0; i < n; i++)
	{
		double score;
		cin >> score;
		pq.push(score);
	}
	cout << fixed;
	cout.precision(3);
	for (int i = 0; i < 7; i++)
	{
		cout << pq.top() << "\n";
		pq.pop();
	}
	return 0;
}