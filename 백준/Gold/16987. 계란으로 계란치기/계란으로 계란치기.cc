#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;
int n, ret;
vector<pair<int, int>> v;
void go(int select, int cnt)
{
	ret = max(cnt, ret);
	if (ret >= n) return;
	if (n == select)
	{
		return;
	}
	if (v[select].first <= 0) // 순차적으로 넘어올 때 이미  깨졌으니 넘김
	{
		go(select + 1, cnt);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (v[i].first <= 0 || i == select) continue;// 이미 깨졌거나 아니면 선택된 계란인 경우
			v[select].first -= v[i].second;
			v[i].first -= v[select].second;
			if (v[select].first <= 0 && v[i].first <= 0)
			{
				go(select + 1, cnt + 2);
			}
			else if (v[select].first <= 0 || v[i].first <= 0)
			{
				go(select + 1, cnt + 1);
			}
			else
			{
				go(select+1, cnt);
			}
			v[select].first += v[i].second;
			v[i].first += v[select].second;
		}
	}
	return;
}
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	go(0, 0);
	cout << ret;

}


