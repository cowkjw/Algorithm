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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int idx1 = 0, idx2 = 0;
	vector<int> res;
	while (true)
	{
		int maxVal = -1;
		for (int i = idx1; i < n; i++)
		{
			for (int j = idx2; j < m; j++)
			{
				if (a[i] == b[j])
				{
					maxVal = max(maxVal, a[i]);
				}
			}
		}
		if (maxVal == -1) break;
		while (idx1 < n && a[idx1] != maxVal) idx1++;
		while (idx2 < m && b[idx2] != maxVal) idx2++;
		
		res.push_back(maxVal);
		idx1++;
		idx2++;
	}
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

    return 0;
}