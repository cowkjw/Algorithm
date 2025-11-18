#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

const int dx[4] = { 0,0, -1, 1 };
const int dy[4] = { -1,1,0,0 };

int n, m;
int prefix[100001];

int vis[20001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	string str;
	cin >> str;
	int ans = 0;
	
	int idx =0;
	while (true)
	{
		ans++;
		string num = to_string(ans);
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i] == str[idx])
			{
				idx++;
			}
			if (idx == str.size())
			{
				cout << ans;
				return 0;
			}
		}
	} 
	cout << ans;
	return 0;
}
