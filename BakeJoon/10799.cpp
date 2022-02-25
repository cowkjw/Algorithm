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
			if (str[i-1]=='(') // 레이저 
			{
				S.pop();
				count += S.size();
				
			}
			else
			{
				S.pop(); // 막대 절단 완료 pop
				count++; // 막대의 끝이므로 +1
			}

		}
	}
	cout << count;
	
	
	return 0;
}