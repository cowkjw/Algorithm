#include <iostream>

using namespace std;

int main() {


	int N, M;
	int* List;
	int sum = 0;
	int _sum;

	cin >> N >> M;

	List = new int[N];


	for (int i = 0; i < N; i++)
	{
		cin >> List[i];
	}


	for (int j = 0; j < N; j++)
	{
		for (int k = j + 1; k < N; k++)
		{

			for (int z = k + 1; z < N; z++)
			{
				_sum = List[j] + List[k] + List[z];
				if (_sum <= M) //sum <= M
				{
					sum > _sum ? sum = sum : sum = _sum;
				}
			}
		}
	}

	cout << sum;
	delete[] List;

}