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
using namespace std;
#define INF 987654321


using ll = long long;
using pii = pair<int, int>;

int n, m,k;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

int parent[30001];
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
int groupCandyCount[30001];
int groupSize[30001];
int candyCount[30001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m>>k;
	for (int i = 1; i <= n; i++) 
		parent[i] = i;

	for (int i = 1; i <= n; i++) // 가지고 있는 캔디 수
	{
		int candy;
		cin >> candy;
		candyCount[i] = candy;
	}

	for (int i = 0; i < m; i++) // 친구 관계
	{
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	for (int i = 1; i <= n; i++)
	{
		int p = Find(i); // 집합 대표
		groupCandyCount[p] += candyCount[i];
		groupSize[p] += 1;
	}
	int ans = 0;
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++) // 그룹 번호
	{
		for (int j = 1; j < k; j++) // 울릴 수 있는 인원: 1명 ~ (k-1)명
		{   //  i번째 그룹을 털지 않는 경우
			//	이전 그룹까지의 결과를 그대로 가져옴
			dp[i][j] = dp[i - 1][j]; 
			if (groupSize[i] == 0)// i번째 그룹이 없으면 패스
				continue; 
			// i번째 그룹을 터는 경우
			 // 조건: 그룹 인원(groupSize[i])이 남은 인원(j)보다 작거나 같아야 함
			if (j - groupSize[i] >= 0)
			{
				// i번째 그룹을 털면:
				//  이 그룹의 인원(groupSize[i])만큼 "울리는 인원"이 증가
				//  따라서 이전에는 (j - groupSize[i])명만 울렸어야 함
				//  그때의 최댓값(dp[i-1][j-groupSize[i]])에 
				//  현재 그룹의 사탕(groupCandyCount[i])을 더함
				//  "안 털었을 때"와 "털었을 때" 중 더 큰 값을 선택
				dp[i][j] = max(dp[i][j], dp[i - 1][j - groupSize[i]] + groupCandyCount[i]);
			}
		}
	}
	cout << dp[n][k-1] << "\n";

	return 0;
}