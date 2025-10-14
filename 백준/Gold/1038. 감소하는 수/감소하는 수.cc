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

int n;
vector<ll> result;

void dfs(ll num)
{
	result.push_back(num);

	int last = num % 10; // 마지막 자리
	for (int next = 0; next < last; next++) 
	{
		dfs(num * 10 + next); // 마지막 자리보다 작은 수만 붙인다
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	
	for (int i = 0; i <= 9; i++) 
	{
		dfs(i);
	}

	sort(result.begin(), result.end());
	if (n >= result.size()) cout << -1;
	else cout << result[n];
    return 0;
}