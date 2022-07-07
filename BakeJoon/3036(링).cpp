#include <bits/stdc++.h>
using namespace std;


int GCD(int a, int b) // �ִ� ����� 
{
	return b ? GCD(b, a % b) : a; // b�� 0�� �ƴϸ� GCD ȣ�� 0�̶�� return a
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int firstRing;
	cin >> firstRing;

	for (int i = 0; i < N-1; i++)
	{
		int temp;
		cin >> temp;
		int gcd = GCD(firstRing, temp);
		cout << firstRing / gcd << "/" << temp / gcd<<"\n";
	}
	return 0;

}

