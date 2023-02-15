#include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	priority_queue<int> pq;
	for (int i = 0; i < n * n; i++)
	{

		int number;
		cin >> number;
		
		pq.push(-number);	
		if (n < pq.size())
		{
			pq.pop();
		}
	}


	cout << -pq.top();

	return 0;
}
