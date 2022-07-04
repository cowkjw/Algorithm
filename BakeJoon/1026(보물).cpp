#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += A[i] * B[i];

	cout << sum;

	return 0;

}

