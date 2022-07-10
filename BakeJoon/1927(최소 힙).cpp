#include <bits/stdc++.h>
using namespace std;


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq; //Min-Heap

	int N; // 연산 개수
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		if (input == 0)
		{
			if (pq.size() == 0)
				cout << 0 << "\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(input);
		}
	}

	return 0;

}

