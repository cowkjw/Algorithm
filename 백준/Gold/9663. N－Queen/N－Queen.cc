#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define INF 987654321
#define MOD 1000000
using namespace std;

int n, ans;
int col[16]; // 해당 행의 열을 저장
bool Check(int x)
{
	for (int i = 1; i < x; i++) // 열 검사
	{
		if (col[i] == col[x] || abs(i - x) == abs(col[i] - col[x])) return false;
	}
	return true;
}
void Recur(int x)
{
	// n개를 다 놓은 경우 (행 마다 하나씩 있는 경우)
	if (x > n) {
		ans++;
		return;
	}


	for (int i = 1; i <= n; i++)
	{
		col[x] = i;
		if (Check(x))
		{
			Recur(x + 1);
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	Recur(1);
	cout << ans;
	return 0;
}