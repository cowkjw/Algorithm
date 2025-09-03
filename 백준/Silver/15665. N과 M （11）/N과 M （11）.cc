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

int n, m;

set<vector<int>> s;
vector<int> vec(7);
void BackTracking(vector<int> numbers)
{
	if (numbers.size() == m)
	{
		s.insert(numbers);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		numbers.emplace_back(vec[i]);
		BackTracking(numbers);
		numbers.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	vector<int> temp;
	BackTracking(temp);

	for (auto k : s)
	{
		for (int i = 0; i < m; i++)
		{
			cout << k[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}