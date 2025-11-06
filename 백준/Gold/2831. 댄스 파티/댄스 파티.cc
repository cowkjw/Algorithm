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

int n, m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vector<int> boyU, girlD;
	vector<int> boyD, girlU;
	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;
		if (h < 0)
		{
			boyD.push_back(-h); // 나보다 작은 사람을
		}
		else
		{
			boyU.push_back(h);
		}

	}
	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;
		if (h < 0)
		{
			girlD.push_back(-h); // 나보다 작은 사람을
		}
		else
		{
			girlU.push_back(h);
		}
	}
	sort(boyU.begin(), boyU.end());
	sort(girlU.begin(), girlU.end());
	sort(boyD.begin(), boyD.end());
	sort(girlD.begin(), girlD.end());
	// 키가 큰 여자와 작은 남자 매칭
	int ans = 0;
	for (int i = 0, j = 0; i < boyU.size() && j < girlD.size();)
	{
		int boy = boyU[i];
		int girl = girlD[j];
		if (girl > boy)
		{
			i++, j++, ans++;
		}
		else // 남자가 더 큰 경우
		{
			j++;
		}
	}

	for (int i = 0, j = 0; i < boyD.size() && j < girlU.size();)
	{
		int boy = boyD[i];
		int girl = girlU[j];
		if (girl < boy)
		{
			i++, j++, ans++;
		}
		else // 남자가 더 작은 경우
		{
			i++;
		}
	}

	cout << ans;
	return 0;
}
