#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> temp;

	string ans;
	int cnt = 1;
	
	for (int i = 0; i <N; i++)
	{
		int X;
		cin >> X;

		while (cnt <= X)
		{
			temp.push_back(cnt++);
			ans += '+';
		}
		if (!temp.empty() && temp.back() == X)
		{
			ans += '-';
			temp.pop_back();
		}
		else
		{
			cout << "NO";
			break;
		}


	}

	if (temp.empty())
	{
		for (auto i : ans)
			cout << i << "\n";
	}

}




