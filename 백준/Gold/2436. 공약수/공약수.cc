#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;


int GCD(int a, int b)
{
	int tmp = 0;
	while (a % b)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return b;
}
vector<pair<int, int>> vec;
bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first + a.second < b.first + b.second;
}
int main()
{
	int gcd, lcm;
	cin >> gcd >> lcm;
	long long num = lcm/gcd; // L/G  = X*Y
	long long minSum = 1e9;
	for (int i = 1; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			int x = i;
			int y = num / i;

			if (GCD(x, y) == 1)
			{
				vec.push_back({ gcd * x , gcd * y });
			}
		}
	}
	sort(vec.begin(), vec.end(), comp);
	cout << vec[0].first << " " << vec[0].second;
	// GCD (6) * LCM(180) = a*b = G*X * G* Y = G^2(X*Y) 
	//  LCM = G(X*Y) , L/G  = X*Y
	//180 / 6 = a * b a * b = 30
	return 0;
}