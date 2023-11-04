#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;

int n, m;
int main()
{
	cin >> n >> m;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	set<vector<int>>s;
	sort(v.begin(), v.end());

	do
	{
		vector<int> temp;
		for (int i = 0; i < m; i++)temp.push_back(v[i]);
		sort(temp.begin(), temp.end());
		s.insert(temp);
	} while (next_permutation(v.begin(), v.end()));

	for (const auto& vec : s)
	{
		for (const auto i : vec) cout << i << " ";
		cout << "\n";
	}
}


