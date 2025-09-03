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

int n, m;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<int> A(n);
	vector<int> B(m);
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < m; i++) cin >> B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<int> ans;
	int a = 0; int b = 0;

	while (a < n && b < m)
	{
		if (A[a] < B[b])
		{
			ans.push_back(A[a]);
			a++;
		}
		else if (A[a] == B[b])
		{
			a++;
			b++;
		}
		else
		{
			b++;
		}
	}
	while (a < n)
	{
		ans.push_back(A[a]);
		a++;
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}