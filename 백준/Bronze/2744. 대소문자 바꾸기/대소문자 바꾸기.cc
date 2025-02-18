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

using namespace std;
#define INF 987654321
const int dx[4]{ 1,-1,0,0 };
const int dy[4]{ 0,0,1,-1 };

unordered_map<string, string > um;
int main()
{
	string str;
	cin >> str;
	transform(str.begin(), str.end(),str.begin(),
		[](char& ch)
	{
			if (islower(ch)) return toupper(ch);
			else return tolower(ch);
	});
	cout << str;
	return 0;
}
