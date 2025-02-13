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


int parent[51];
int n, m, cntKnow;
vector<int> know;

int Find(int x)
{
	if (parent[x] != x)
	{
		parent[x] = Find(parent[x]);  // 경로 압축
	}
	return parent[x];
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	cin >> cntKnow;
	unordered_set<int> s;

	for (int i = 0; i < 51; i++)
	{
		parent[i] = i;
	}

	if (cntKnow)
	{
		for (int i = 0; i < cntKnow; i++)
		{
			int num;
			cin >> num;
			know.push_back(num);
			s.insert(num);
		}

		int firstKnown = know[0];

		for (int i = 1; i < cntKnow; i++)
		{
			Union(firstKnown, know[i]);
		}
	}

	int ans = 0;

	vector<vector<int>> party;
	for (int i = 0; i < m; i++) // 파티 수
	{
		int cnt;
		cin >> cnt;
		vector<int> tmp(cnt);
		for (int j = 0; j < cnt; j++) // 파티원
		{
			cin >> tmp[j];
		}
		// 파티원들 유니온

		for (int k = 1; k < (int)tmp.size(); k++)
		{
			Union(tmp[0], tmp[k]);
		}
		party.push_back(tmp);
	}

	for (const auto& par : party)
	{
		bool canLie = true;

		for (int k : know)
		{
			for (int p : par)
			{
				if (Find(k) == Find(p))
				{
					canLie = false;
					break;
				}
			}
			if (!canLie) break;
		}

		if (canLie) ans++;
	}

	cout << ans;

	return 0;
}