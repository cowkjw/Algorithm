#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;





int main()
{
	int N, route = 1;
	int layer = 6;
	int End = 1;

	cin >> N;

	while (1)
	{
		if (End >= N)
		{
			cout << route;
			break;
		}
		End += layer;
		layer += 6;
		route++;
	}

	return 0;
}