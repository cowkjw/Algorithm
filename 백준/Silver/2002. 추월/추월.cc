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
vector<string> board;
int vis[101][101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	unordered_map<string, int> um, um2;
	vector<string> vec;
	for (int i = 0; i < n; i++) // 들어간 순서
	{
		string str;
		cin >> str;
		um[str] = i;
		vec.push_back(str);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) // 나온 순서
	{
		string str;
		cin >> str;
		um2[str] = i;
	}
	// 내 앞에 있는 차들
	for (const auto& s : vec)
	{
		string cur = s;

		// 내가 나간 순서보다 앞차가 나가지 않은 경우
		// 내가 1번으로 나갔는데 내 순서까지 들어온 차량 순서로 비교했을 때
		// 그 차가 나보다 늦게 나갔다면 내가 추월한거
		for (int j = 0; j < um[cur]; j++) 
		{
			if (um2[vec[j]] > um2[cur])
			{
				ans++;
				break;
			}
		}
	}

	cout << ans;
	return 0;
}
