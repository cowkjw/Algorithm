#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	queue <int> q;
	vector<int> v;
	int N, K;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		q.push(i + 1);
	
	cout << "<";

	while (q.size()!=1)
	{
		for (int i = 0; i < K-1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front()<<", ";
		q.pop();

	}
	cout << q.front() << ">";

	return 0;

}

