#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;

int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector <pair<string, pair<int, pair<int, int>>>> v;
	for (int i = 0; i < n; i++)
	{
		string name;
		int a, b, c;
		cin >> name >> a >> b >> c;
		v.push_back({ name,{a ,{b,c}} });
	}

	sort(v.begin(), v.end(), [](pair<string, pair<int, pair<int, int>>>& a, pair<string, pair<int, pair<int, int>>>& b)
		{
			if (a.second.first != b.second.first)
			{
				return a.second.first > b.second.first;
			}
			else if (a.second.first == b.second.first)
			{
				if (a.second.second.first != b.second.second.first)
				{
					return a.second.second.first < b.second.second.first;
				}
				else
				{
					if (a.second.second.second != b.second.second.second)
					{
						return a.second.second.second > b.second.second.second;
					}
					else
					{
						return a.first < b.first;
					}
					
				}
			}
		});

	for (const auto& item : v)
	{
		cout << item.first<<'\n';
	}

	return 0;
}