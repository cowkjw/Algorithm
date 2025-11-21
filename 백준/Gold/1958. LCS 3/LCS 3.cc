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
#include <cstring>
using namespace std;
#define INF 987654321
#define LL_INF 1e15


using ll = long long;
using pii = pair<int, int>;

int n, m, k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
const int dh[] = { -1,1 };

int parent[200001];
int Find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// 문자열 분리 (split)
vector<string> split(string s, char delim)
{
	vector<string> result;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim))
	{
		if (!item.empty())
		{  // 빈 문자열 제외
			result.push_back(item);
		}
	}

	return result;
}
string trim(string s)
{
	if (s.empty()) return s;

	int start = 0, end = s.length() - 1;
	while (start <= end && isspace(s[start])) start++;
	while (end >= start && isspace(s[end])) end--;

	if (start > end) return "";
	return s.substr(start, end - start + 1);
}

int dp[101][101][101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str1, str2, str3;
	cin >> str1 >> str2>>str3;
	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 1; j <= str2.size(); j++)
		{
			for (int k = 1; k <= str3.size(); k++)
			{
				if (str1[i - 1] == str2[j - 1]&& str2[j - 1] == str3[k - 1])
				{
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else
				{
					dp[i][j][k] = max({ dp[i - 1][j][k],dp[i][j-1][k],dp[i][j][k-1] });
				}
			}
		}
	}
	cout << dp[str1.size()][str2.size()][str3.size()];
	return 0;
}