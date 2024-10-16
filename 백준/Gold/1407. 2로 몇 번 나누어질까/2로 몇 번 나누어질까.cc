#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;


int main()
{
	long long a, b;
	cin >> a >> b;
	a -= 1;
	// 제곱수로 올려야 할 수에 이전의 제곱수에서 해당 제곱수로 가기 위한 양을 곱함
	long long tmpA = a;

	for (int i = 1; i < 50; i++)
	{
		tmpA += (a /(long long) pow(2, i))*(((long long)pow(2,i)- (long long)pow(2,i-1))); // 이전 제곱수와 현재 제곱수의 차이만큼 
	}
	long long tmpB = b;

	for (int i = 1; i < 50; i++)
	{
		tmpB += (b / (long long)pow(2, i)) * ((long long)(pow(2, i) - (long long) pow(2, i - 1))); // 이전 제곱수와 현재 제곱수의 차이만큼 
	}
	cout << tmpB - tmpA;
	return 0;
}