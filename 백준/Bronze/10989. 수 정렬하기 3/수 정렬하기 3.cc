#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;





int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int numbers[100001] = {};
	int number;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> number;
		numbers[number] += 1;
	}

	

	for (int i = 0; i < 10001; i++)
	{
		for(int j = 0;j<numbers[i];j++)
		cout << i << "\n";
	}

	return 0;
}