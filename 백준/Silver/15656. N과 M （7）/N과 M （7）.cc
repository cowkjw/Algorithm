#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;
int n, m;
vector<int> v;
vector<int> res;
void go(int idx)
{
	if (m == res.size())
	{
		for (const auto& i : res)
		{
			cout << i << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		res.push_back(v[i]);
		go(i);
		res.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	go(0);

	return 0;
}


