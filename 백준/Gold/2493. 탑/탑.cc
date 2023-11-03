#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#define X first 
#define Y second
using namespace std;
typedef long long ll;
int n;
	int main()
	{
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		stack<int> s;
		for (int i = 0; i < n; i++)
		{
			while (!s.empty() && v[s.top()] < v[i])
			{
				s.pop();
			}
			if (s.empty()) cout << 0 << " ";
			else cout << s.top() + 1 << " ";
			s.push(i);
		}
		return 0;
	}
