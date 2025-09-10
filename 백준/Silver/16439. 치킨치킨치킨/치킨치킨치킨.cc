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

vector<string> split(string input, string del)
{
	vector<string> retStr;

	long long pos = 0;
	string token = "";
	while ((pos = input.find(del)) != -1)
	{
		token = input.substr(0, pos);
		retStr.push_back(token);
		input.erase(0, pos + del.size());
	}
	retStr.push_back(input);
	return retStr;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n, m;
	cin >> n >> m;
	int ans = 0;
	vector<vector<int>> pref(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> pref[i][j];

	// 치킨 1개, 2개, 3개 선택 다 확인
	for (int i = 0; i < m; i++)
	{
		for (int j = i; j < m; j++) 
		{
			for (int k = j; k < m; k++) 
			{
				int sum = 0;
				for (int p = 0; p < n; p++) 
				{
					sum += max({ pref[p][i], pref[p][j], pref[p][k] });
				}
				ans = max(ans, sum);
			}
		}
	}
	cout << ans;

	return 0;
}