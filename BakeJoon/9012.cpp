#include<iostream>
#include<stack>
using namespace std;

bool isVPS(string str)
{
	stack<char> s;
	

	for (int i = 0; i < str.size(); i++)
	{

		if (s.empty())
		{
			s.push(str[i]);
			continue;
		}

		if (s.top() == ')' && s.top() != str[i])
		{
			s.push(str[i]);
			
		}
		else if (s.top() != str[i])
		{
			s.pop();
		}
		else
		{
			s.push(str[i]);
		}

	}

	if (s.empty())
		return 1;
	else
		return 0;
}

int main()
{
	string str;
	int N;

	

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (isVPS(str))
		{
			cout << "YES"<<endl;
		}
		else
		{
			cout << "NO" << endl;
		}


	}

	return 0;
}