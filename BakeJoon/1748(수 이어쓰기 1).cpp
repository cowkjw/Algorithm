#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int ans = 0;
	int i = 1;
	while (i <= N)
	{
		ans += (N - i + 1); // �� �ڸ������� ����
		i *= 10;

	}
	cout << ans;
	return 0;

}

