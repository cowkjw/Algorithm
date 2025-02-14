#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <functional>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		cout << str.front() << str.back() << '\n';
	}
	return 0;
}