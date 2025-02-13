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
using namespace std;

int n, m;
set<vector<int>> se;
void Backtracking(const vector<int>& vec,vector<int>& tmp, int start)
{
	if ((int)tmp.size() == m)
	{
		if (se.count(tmp) == 0)
		{
			se.insert(tmp);
			for (int i = 0; i < m; i++)
			{
				cout << tmp[i] << " ";
			}
			cout << '\n';
		}
		return;
	}

	for (int i = start; i < n; i++)
	{
		tmp.push_back(vec[i]);
		Backtracking(vec, tmp,i);
		tmp.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	cin >> n >> m;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	vector<int> tmp;
	Backtracking(vec, tmp,0);
	return 0;
}