#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int n, c;
map<int, int> m1, m2;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return m2[a.first] < m2[b.first];
	}
	return a.second > b.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		m1[num]++;
		if(m2.find(num)==m2.end())
		m2[num] = i;
	}

	vector<pair<int, int>> v(m1.begin(), m1.end());



	sort(v.begin(), v.end(), cmp);

	for (auto& i : v)
	{
		while (i.second--)
			cout << i.first << " ";
	}


	return 0;
}