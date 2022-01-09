#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;





int main()
{
	stack<int> s;
	int K;
	int sum = 0;

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;

		if (num == 0)
			s.pop();
		else
		{
			s.push(num);
		}
	}


	while (1)
	{
		if (s.empty())
			break;
		else
		{
			sum += s.top();
			s.pop();
		}
	
	}

	cout << sum;

	return 0;
}