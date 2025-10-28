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


int n, m, d;
int arr[21][21];
int ans = INF;
vector<int> star, link;
void Back(int cnt)
{
	if (cnt == n) // 끝까지 다 고른 경우
	{
		if (star.empty() || link.empty()) return;
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < star.size(); i++)
		{
			for (int j = i + 1; j < star.size(); j++)
			{
				sum1 += arr[star[i]][star[j]] + arr[star[j]][star[i]];
			}
		}

		for (int i = 0; i < link.size(); i++)
		{
			for (int j = i + 1; j < link.size(); j++)
			{
				sum2 += arr[link[i]][link[j]] + arr[link[j]][link[i]];
			}
		}
		ans = min(abs(sum2 - sum1), ans);

		return;
	}

	star.push_back(cnt);
	Back(cnt + 1);
	star.pop_back();


	link.push_back(cnt);
	Back(cnt + 1);
	link.pop_back();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	// i번 사람이 선택할 수 있는 사람 
	// j번 사람이 선택할 수 있는 사람

	Back(0);
	cout << ans;
	

	return 0;
}
