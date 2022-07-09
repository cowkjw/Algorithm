#include <bits/stdc++.h>
using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int N;
	int ans = 0;
	cin >> N;
	
	for (int i = 5; i <= N; i *= 5) // 5의 배수마다 나눠서 개수를 구함
		ans += N / i;

	cout << ans;
	return 0;

}

