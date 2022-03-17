#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	queue<int> Q;
	vector<int> v;

	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		Q.push(i);

	int index = 1;

	while (true)
	{
		if (Q.empty())
			break;

		if (index == K)
		{

			v.push_back(Q.front());
			Q.pop();
			index = 1;
		}
		else
		{
			int temp = Q.front();
			Q.pop();
			Q.push(temp);
			index++;
		}

	}
	int size = v.size();
	cout << "<";
	for (int i = 0; i < size; i++)
	{

		if ((i + 1) == size)
		{
			cout << v[i] << ">";
		}
		else
			cout << v[i] << ", ";


	}




}




