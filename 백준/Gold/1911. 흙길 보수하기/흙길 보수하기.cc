#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second

using namespace std;
int n, l;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> l;

	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end());
	int pre = 0;

	int ret = 0;
	for (const auto& pos : v)
	{
		int s, e, need;
		tie(s, e) = pos;
		if (e <= pre) continue; // 이미 해당 구역을 전부 덮은 경우
		if (s < pre)// 해당 구역을 일부 덮은 경우
		{
			need = (e - pre) / l;
			if ((e - pre) % l != 0) need++;
			pre = pre + need * l;
		}
		else
		{
			need = (e - s) / l;
			if ((e - s) % l != 0) need++;
			pre = s + need * l;
		}
		ret += need;
	}

	cout << ret;

	return 0;
}


