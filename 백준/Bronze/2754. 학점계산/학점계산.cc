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
	um["A+"] = "4.3";
	um["A0"] = "4.0";
	um["A-"] = "3.7";
	um["B+"] = "3.3";
	um["B0"] = "3.0";
	um["B-"] = "2.7";
	um["C+"] = "2.3";
	um["C0"] = "2.0";
	um["C-"] = "1.7";
	um["D+"] = "1.3";
	um["D0"] = "1.0";
	um["D-"] = "0.7";
	um["F"] = "0.0";
	string str;
	cin >> str;
	cout << um[str];
	return 0;
}
