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
#include <sstream>
using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const int hDx[] = { -2,-2,-1,-1,1,1,2,2 };
const int hDy[] = { -1,1,-2,2,-2,2,-1,1 };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<string> vec;
	int row = 0, col = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		vec.push_back(str);
	}
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			
			char ch = vec[i][j];
			if (ch == '.') cnt++;
			else
			{
				if (cnt >= 2)
				{
					row++;
				}
				cnt = 0;
			}
		}
		if (cnt >= 2)
		{
			row++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			char ch = vec[j][i];
			if (ch == '.') cnt++;
			else
			{
				if (cnt >= 2)
				{
					col++;
				}
				cnt = 0;
			}
		}
		if (cnt >= 2)
		{
			col++;
		}
	}
	cout << row << " " << col;
	return 0;
}