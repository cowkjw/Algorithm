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
bool check[51];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> arr(n), arr2(n);
	vector<pair<int, int>> arr3;
	for (int i = 0; i < n; i++) 
	{
		cin >> arr[i];
		arr2[i] = arr[i];
		arr3.push_back({ arr[i], i });
	}
	sort(arr3.begin(), arr3.end());
	// 1,2,3
	// 2,3,1
	// 2 = 0, 3 = 1, 1 = 2
	for (int i = 0; i < n; i++)
	{
		int idx = arr3[i].second;
		arr2[idx] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr2[i] << " ";
	}
    return 0;
}