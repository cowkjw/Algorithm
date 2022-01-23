//#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;

bool compare(pair<int, int>& A ,pair<int, int>& B)
{
	if (A.second == B.second)
		return A.first < B.first;
	else
		return A.second < B.second;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int N;
	cin >> N;
	
	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		v[i].first = x;
		v[i].second = y;
	}

	sort(v.begin(), v.end(),compare);

	for (int i = 0; i < N; i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}



}

