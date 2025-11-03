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


int n, m, d;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	string target;
	cin >> target;


	int ans = 0;

	for (int i = 1; i < n; i++)
	{
		string tmpStr;
		cin >> tmpStr;

		vector<int> alph(27, 0);
		for (auto ch : tmpStr)
		{
			int pos = ch - 'A';
			alph[pos] = alph[pos] + 1;
		}

		for (auto ch : target)
		{
			alph[ch - 'A'] = alph[ch - 'A'] - 1;
		}

		int diff = 0;
		for (auto v : alph)
			diff += abs(v);

		if (diff <= 2 && abs((int)tmpStr.size() - (int)target.size()) <= 1)
			ans++;
	}
	cout << ans;
	return 0;
}
