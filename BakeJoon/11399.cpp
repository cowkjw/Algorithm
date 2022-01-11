#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int M;

		cin >> M;

		v.push_back(M);
	}
	int sum = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{

		if (i == 0)
		{
			sum+= v[i];

		}
		else
		{
			for (int j = 0; j <= i; j++)
			{
				sum+= v[j];
			}
		}
		
	}

	cout << sum;

}