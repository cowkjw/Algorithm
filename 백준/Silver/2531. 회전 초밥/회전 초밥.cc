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

int n, d, k, c;

vector<int> v(30001);
unordered_map<int,int>um;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}


	int start = 0; // 시작 접시
	int end = k-1; // k개 연속으로의 구간 끝
	for (int i = start; i < k; i++) // 전체 초밥 종류 세기
	{
		um[v[i]]++;
	}
	int ans = 0;
	while (start < n)
	{
		// 현재 사이즈에 만약 쿠폰 초밥이 없다면 추가
		ans = max(ans, (int)um.size() + (um.find(c) == um.end() ? 1 : 0));
		um[v[start]]--;
		if (um[v[start]] == 0) 
			um.erase(v[start]);
		start++;
		end++;
		um[v[end % n]]++;
	}
	cout << ans;
	return 0;
}