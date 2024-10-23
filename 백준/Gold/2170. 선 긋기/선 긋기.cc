#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define INF 987654321
#define MOD 1000000
using namespace std;

int n;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<pair<int,int>> lines(n);
	for (int i = 0; i < n; i++)
	{
		cin >> lines[i].first >> lines[i].second;
	}

	sort(lines.begin(), lines.end());

	int start = lines[0].first;
	int end = lines[0].second;
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (end > lines[i].first)
		{
			end = max(end,lines[i].second);
		}
		else
		{
			ans += end - start;
			start = lines[i].first;
			end = lines[i].second;
		}
	}

	ans += end - start;
	cout << ans;
	return 0;
}