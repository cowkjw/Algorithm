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
#include <unordered_map>
#include <numeric>
#include <climits>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define INF 987654321

int n, m, d;
bool IsPrime(int start)
{
	if (start == 1) return false;
	if (start == 2) return true;
	if (start % 2 == 0) return false;

	for (int i = 3; i * i <= start; i += 2)
	{
		if (start % i == 0) return false;
	}
	return true;
}

bool IsPalindrome(int num)
{
	string tmpStr = to_string(num);
	int size = tmpStr.size();
	if (size == 1) return true;
	for (int i = 0; i < size / 2; i++)
	{
		if (tmpStr[i] != tmpStr[size - 1 - i]) return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n;
	cin >> n;

	int start = n;
	while (true)
	{
		if (IsPrime(n))
		{
			if (IsPalindrome(n))
			{
				cout << n << '\n';
				break;
			}
		}
		n++;
	}

	return 0;
}
