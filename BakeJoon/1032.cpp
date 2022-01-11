#include <iostream>
using namespace std;

int main()
{
	int N;
	string ans;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		if (ans.empty())
		{
			ans = temp;
		}
		else
		{
			for (int i = 0; i < ans.size(); i++)
			{
				if (ans[i] != temp[i])
					ans[i] = '?' ;
			}
		}
	}
	cout << ans;
}