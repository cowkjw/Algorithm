#include <iostream>
#include <stack>
using namespace std;




int main()
{



	//string AB;
	//int N, j;
	//int cnt = 0;

	//cin >> N;

	//for (int i = 0; i < N; i++)
	//{
	//	cin >> AB;
	//	for (j = 0; j < AB.size();)
	//	{
	//		if (AB[j] == AB[j + 1])
	//		{
	//			AB.erase(j, 2);
	//			j = 0;
	//		}
	//		else
	//		{
	//			j++;

	//		}

	//	}
	//	if (AB.empty())
	//	{
	//		cnt++;
	//	}
	//}
	//cout << cnt;







	int N, cnt = 0;

	cin >> N;
	string AB;

	while (N--)
	{
		cin >> AB;
		stack<char> stack;

		for (int j = 0; j < AB.size(); j++)
		{
			if (stack.empty())
			{
				stack.push(AB[j]);
				continue;
			}
			if (stack.top() == AB[j])
			{
				stack.pop();
			}
			else
			{
				stack.push(AB[j]);
			}

		}

		if (stack.empty())
			cnt++;
	}

	cout << cnt;

	return 0;
}


