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

int parent[100001];
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



int h[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> arr(n);
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int j = 0; j < arr.size(); j++)
	{
		int tmp = arr[j]; // 높이

		if (h[tmp] > 0) // 현재 높이로 날아오고 있는 화살이 있는가??
		{
			h[tmp]--; // 날아왔으니 높이 낮추고
			h[tmp - 1]++; // 지금 낮춘 높이로 날아가는 화살 추가
		}
		else
		{
			ans++;// 현재 높이로 날아오는게 없으니 화살을 하나 추가하고 맞췄으니 낮은 높이로 날아가는 화살 추가
			h[tmp-1]++; 
		}
	}
	
	cout << ans;
	return 0;
}