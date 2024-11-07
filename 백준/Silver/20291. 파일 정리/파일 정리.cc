#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<utility>
#include <set>
#include <map>
using namespace std;


void SplitPoint(string& str)
{
	auto it = find_if(str.begin(), str.end(), [&](char ch)
		{
			return ch == '.';
		});
	int pos = distance(str.begin(), it)+1;
	str = str.substr(pos);
}
int main() 
{
	int n;
	cin >> n;

	map<string, int> m;

	while (n--)
	{
		string str;
		cin >> str;
		SplitPoint(str);
		m[str] += 1;
	}

	for (const auto& i : m)
	{
		cout << i.first << " "<<i.second<<"\n";
	}
	return 0;
}