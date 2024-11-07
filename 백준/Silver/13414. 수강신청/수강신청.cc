#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<utility>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
using namespace std;


void SplitPoint(string& str)
{
	auto it = find_if(str.begin(), str.end(), [&](char ch)
		{
			return ch == '.';
		});
	int pos = distance(str.begin(), it) + 1;
	str = str.substr(pos);
}
int main()
{
	int n, k;
	cin >> n >> k;
	unordered_map<string, int> m;

	for (int i = 0; i < k; i++)
	{
		string student;
		cin >> student;
		m[student] = i;
	}

	vector<pair<string, int>> vec(m.begin(), m.end());

	sort(vec.begin(), vec.end(), [&](const pair<string, int> a, const pair<string, int> b)
		{
			return a.second < b.second;
		});

	for (int i = 0; i < min(n,(int)vec.size()); i++)
	{
		cout << vec[i].first << '\n';
	}
	return 0;
}