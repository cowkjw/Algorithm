#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> v(N);

	int ans = 0;
	int left=0, right=0;

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int sum = 0;
	while (right <= N)
	{
		if (sum >= M) // ũ�⶧���� ���� ���� ����
			sum -= v[left++];
		else if (N == right)
			break;
		else
			sum += v[right++];// �۴ٸ� ������ �����͸� �Ű� �� ������
		
		
		if (sum == M)
			ans++;

	}

	cout << ans;


	return 0;

}

