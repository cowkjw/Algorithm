#include <bits/stdc++.h>
using namespace std;



int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int count = 0;
	string str;
	stack<char> S;

	cin >> str;


	for (int i = 0; i < str.length(); i++)
	{
		if (str[i]=='(')
		{
			S.push(str[i]);
		}
		else
		{
			if (str[i-1]=='(') // ������ 
			{
				S.pop();
				count += S.size();
				
			}
			else
			{
				S.pop(); // ���� ���� �Ϸ� pop
				count++; // ������ ���̹Ƿ� +1
			}

		}
	}
	cout << count;
	
	
	return 0;
}