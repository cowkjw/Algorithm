#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	string str;
	cin >> str;

	int cnt = 0;
	while (str.size() > 1)
	{
		cnt++;
		int num = 0;
		for (auto ch : str)
		{
			num += atoi(&ch);
		}
		str = to_string(num);
	}
	cout << cnt << '\n';
	cout << ((stoi(str) % 3 == 0) ? "YES" : "NO");
	return 0;
}
