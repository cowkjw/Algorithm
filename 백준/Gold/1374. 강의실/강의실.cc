#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> v;
	priority_queue<int> pq;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ b,c });
	}
	
	sort(v.begin(), v.end());

	int ret = 0;
	for (const auto& i : v)
	{
		while (!pq.empty() && i.first >= -pq.top()) // 강의실 유지
		{
			pq.pop();
		}
		pq.push({ -i.second });
		ret = max(ret, (int)pq.size());
	}
	cout << ret;
	return 0;
}

