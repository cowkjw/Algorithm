#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, mp, mf, ms, mv;
int arr[16][6];
int ret = INF;

bool check(int a, int b, int c, int d)
{
	if (a >= mp && b >= mf && c >= ms && d >= mv) return true;

	return false;
}

bool comp(pair<vector<int>, int> a, pair<vector<int>, int> b)
{
	if (a.second != b.second)
	{
		return a.second < b.second;
	}
	return a.first < b.first;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[i][j];
		}
	}
	vector<pair<vector<int>,int>> v;
	for (int i = 0; i < (1 << n); i++) // 몇개 선택할지
	{
		int cnt = 0;
		int a, b, c, d;
		a = b = c = d = 0;
		vector<int> temp;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				cnt += arr[j][4];
				a += arr[j][0];
				b += arr[j][1];
				c += arr[j][2];
				d += arr[j][3];
				temp.push_back(j+1);
			}
		}
		if (check(a, b, c, d))
		{
			if (ret >= cnt)
			{
				ret = cnt;
				v.push_back({ temp,ret });
			}
		}
	}
	if (v.size() == 0)
	{
		cout << -1;
		return 0 ;
	}

	sort(v.begin(), v.end(), comp);
	cout << ret << '\n';
	for (const auto& i : v[0].first)
		cout << i << " ";
	return 0;
}
