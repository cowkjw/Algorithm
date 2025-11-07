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

const int dx[]{ 0,0,1,-1 };
const int dy[]{ 1,-1,0,0 };


int n, m;
set<vector<int>> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> n >> m;
	vector<int> arr(n+1);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	queue<pair<vector<int>,int>> q;
	q.push({ arr,0 });
	s.insert(arr);

	while (!q.empty())
	{
		auto [tmpArr, cnt] = q.front();

		q.pop();

		bool sorted = true;

		for (int i = 2; i <= n; i++)
		{
			if (tmpArr[i] < tmpArr[i - 1])
			{
				sorted = false;
				break;
			}
		}

		if (sorted)
		{
			cout<<cnt;
			return 0;
		}

		for (int i = 1; i + m - 1 <= n; i++)
		{
			// 뒤집기
			auto tmp = tmpArr;
			reverse(tmp.begin() + i, tmp.begin() + i + m);
			if(s.insert(tmp).second)
				q.push({ tmp, cnt + 1 });
		}
	}

	
	cout << -1;
	return 0;
}
