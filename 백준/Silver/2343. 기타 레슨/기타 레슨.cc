#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321

vector<int> v;
int n, m, sum, lo, hi, mx,mid;
bool check(int mid)
{
	if (mx > mid) return false;// 블루레이 크기가 작아서 강의를 담을 수 없음
	int tmp = mid;
	int num = 0; //개수

	for (int i = 0; i < n; i++)
	{
		if (mid - v[i] < 0) // 블루레이 한 장을 다 쓴 경우
		{
			mid = tmp; // 다시 블루레이 갱신
			num++; // 사용 블루레이 개수
		}
		mid -= v[i];
	}
	if (mid != tmp) num++; // 마지막 블루레이도 사용했다면
	return m >= num;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	v.resize(n + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
		mx = max(v[i], mx);
	}
	hi = sum;
	int ret = 1e9;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2; // 블루레이 최대 크기

		if (check(mid))
		{
			ret = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;

	}
	cout << ret;

	return 0;
}
