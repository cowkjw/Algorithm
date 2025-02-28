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

using namespace std;
#define INF 987654321

int n,ans;
int arr[9];
int visited[9];
vector<int> vec;	
void Back(int idx)
{
	if (idx == n)
	{
		int sum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			sum += abs(vec[i] - vec[i + 1]);
		}
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i]) continue;
		visited[i] = 1;
		vec.push_back(arr[i]);
		Back(idx+1);
		visited[i] = 0;
		vec.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	Back(0);
 	cout << ans;
	return 0;
}
