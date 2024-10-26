#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include<map>

#define INF 987654321
#define MOD 1000000
using namespace std;


int n, m;
map<string, int> ma;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (str.size() >= m)
		{
			ma[str] += 1;
		}
	}

	vector<pair<string,int>> vec(ma.begin(), ma.end());

	sort(vec.begin(), vec.end(), [&](const pair<string, int>& a, const pair<string, int >& b)
		{
			if (b.second != a.second) return a.second > b.second;
			if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();
			return a.first < b.first;
		});
	for (const auto& s : vec)
	{
		cout << s.first << '\n';
	}
	return 0;
}