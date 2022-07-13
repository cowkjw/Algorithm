#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int price;
		cin >> price;
		v.push_back(price);
	}

	sort(v.begin(), v.end());
	int sum = 0;

	int ans;

	for (int j = 0; j < v.size(); j++)
	{
		int egg = N;
		int tSum = 0;
		int temp = v[j];
		for (int i = 0; i < M; i++)
		{
			if (egg == 0)
				break;
			if (v[i] >= temp)
			{
				tSum += temp;
				egg--;

			}
		}
		if (tSum > sum)
		{
			sum = tSum;
			ans = temp;
		}
		
	}

	cout << ans << " " << sum;

	return 0;

}

