#include <iostream>
#include <stack>
using namespace std;




int main()
{

	string AB;
	int N, cnt = 0;

	cin >> N;

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


