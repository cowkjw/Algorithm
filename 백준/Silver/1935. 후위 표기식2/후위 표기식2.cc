#include <bits/stdc++.h>
using namespace std;
int n;
double arr[27];
stack<double> s;
string str;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++)
	{
		double num;
		cin >> num;
		arr[i] = num;
	}

	for (const auto& ch : str)
	{
		if (isalpha(ch))
		{
			s.push(arr[ch - 'A']);
		}
		else if (ch == '*' || ch == '+' || ch == '/' || ch == '-')
		{
			if (!s.empty())
			{
				double b = s.top();
				s.pop();
				double a = s.top();
				s.pop();
				switch (ch)
				{
				case '*':
					s.push(a * b);
					break;
				case '/':
					s.push(a / b);
					break;
				case '+':
					s.push(a + b);
					break;
				case '-':
					s.push(a - b);
					break;
				}
			}
		}
	}

	cout << fixed; 
	cout.precision(2);
	cout << s.top();

	return 0;
}
