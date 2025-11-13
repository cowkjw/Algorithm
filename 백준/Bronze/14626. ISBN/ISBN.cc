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

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;


int solve(int idx, const string& str)
{
	int ans = 0;
	int total = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (idx == i)
		{
			continue;
		}
		else
		{
			int num = (str[i] - '0');
			if (i % 2 != 0)
			{
				total += 3 * num;
			}
			else
			{
				total += num;
			}
		}
	}
	int w = (idx % 2 ? 3 : 1);  // 빠진 자리의 가중치

	// x * w ≡ -total (mod 10)
	int rem = (10 - (total % 10)) % 10;

	int x;
	if (w == 1) x = rem;
	else x = (rem * 7) % 10;
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;
	cout << solve(str.find('*'), str);
	
	return 0;
}
