#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> A;
	vector<int> B;
	int X, Y;
	cin >> X >> Y;

	vector<int> C(X + Y);
	for (int i = 0; i < X; i++)
	{
		int num;
		cin >> num;
		A.push_back(num);
	}
	for (int i = 0; i < Y; i++)
	{
		int num;
		cin >> num;
		B.push_back(num);
	}
	
	int indexA = 0;
	int indexB = 0;
	int indexC = 0;
	while (indexA < X && indexB < Y)
	{
		if (A[indexA] < B[indexB])
			C[indexC++] = A[indexA++];
		else
			C[indexC++] = B[indexB++];
	}

	while (indexA < X)
		C[indexC++] = A[indexA++];
	while (indexB < Y)
		C[indexC++] = B[indexB++];

	for (auto i : C)
		cout << i << " ";

}




