#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <cmath>
#include <set>
#include <unordered_set>
#include <numeric>

using namespace std;
#define INF 987654321
const int dx[4]{ 1,-1,0,0 };
const int dy[4]{ 0,0,1,-1 };


inline long long Func(long long a, long long b)
{
	return (a + b) * (a - b);
}
long long n, m;
int main()
{
	cin >> n>>m;
	cout << Func(n, m);
	return 0;
}
