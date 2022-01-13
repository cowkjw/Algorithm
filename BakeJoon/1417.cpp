#include <iostream>
#include <vector>
using namespace std;



int main()
{
	vector<int> v;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int cnt;
		cin >> cnt;
		v.push_back(cnt);
	}


	int num = 0;

	while (1)
	{
		int index = 0;
		int max = 0;


		for (int i = 0; i < N; i++)
		{
			if (v[i] >= max)
			{
				max = v[i];
				index = i;
			}
		}


		if (index == 0)
		{
			break;
		}
		else
		{
			v[index]--;
			v.front()++;
			num++;
		}
	}


	cout << num;

	return 0;
}
