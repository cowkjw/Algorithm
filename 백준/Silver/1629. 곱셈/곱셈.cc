#include <bits/stdc++.h>
#define INF -987654321
typedef long long ll;
using namespace std;

ll a, b, c;
ll Recursive(ll a, ll b)
{
	if (b == 1) return a%c;

	ll ret = Recursive(a, b / 2);
	ret = (ret * ret) % c; //2^8을 2^4 x 2^4 와 같은 경우
	if (b % 2) // 홀수인 경우
	{
		ret = (ret * a) % c;  // a = n^1
	}

	return ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> a >> b >> c;

	cout << Recursive(a,b);
	return 0;
}