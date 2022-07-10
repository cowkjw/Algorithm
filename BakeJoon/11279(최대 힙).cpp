#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	priority_queue<int> q;

	cin >> N;
	
	while (N--)
	{
		int input;
		cin >> input;
		if (input == 0)
			if (q.size() != 0)
			{
				cout << q.top() << "\n";
				q.pop();
			}
			else
				cout << 0 << "\n";
		else
			q.push(input);
	}
	
	return 0;

}

