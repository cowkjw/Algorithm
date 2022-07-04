#include <bits/stdc++.h>
using namespace std;

long long ans;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<long long> v;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int wood;
		cin >> wood;
		v.push_back(wood);
	}
	long long Max = *max_element(v.begin(), v.end());
	long long left = 0;
	long long right = Max;
	long long mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		long long woods = 0;

		for (int i = 0; i < N; i++)
		{
			if (v[i] > mid) // �ڸ��� ���̺��� ū ����
				woods += v[i] - mid;
		}

		if (woods >= M) // ���� ����
		{
			ans = mid;
			left = mid + 1;

		}
		else // �ʹ� ���� ���� ��� 
		{
			right = mid - 1;

		}

	}
	cout << ans;

	return 0;

}

