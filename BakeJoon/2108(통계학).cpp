#include <bits/stdc++.h>
using namespace std;

int cnt[8001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int Max =0;
	bool isSecond = false;
	int third = 0;
	cin >> N;
	vector<int>v(N);
	double first = 0;

	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
		first += v[i];
		cnt[v[i] + 4000]++;
	}
	sort(v.begin(), v.end());
	int second = v[N / 2];
	int forth = v.back() - v.front();
	for (int i =v.front()+4000;i<=v.back()+4000; i++)
	{
		
		if (Max == cnt[i]) // 
		{
			if (isSecond) // 두번째라면 (정렬되어있기때문)
			{
				third = i - 4000; // 저장 
				isSecond = false; // 다시 false 혹시나 Max가 더 큰게 있을 수 있기때문에
			}

		}
		if (Max < cnt[i]) 
		{
			Max = cnt[i];
			third = i - 4000;
			isSecond = true;
		}
	}
	first = round(first / (double)N);
	cout << (int)first << "\n" << second << "\n" << third << "\n" << forth;
	return 0;

}

