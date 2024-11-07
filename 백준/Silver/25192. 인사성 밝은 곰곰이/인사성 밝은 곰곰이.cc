#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<utility>
#include <set>
using namespace std;


int main()
{
	int ans = 0;
	int n;

	cin >> n;
		
set<string> gomgom;
	while (n--)
	{
		string str;
		cin >> str;

		if (str == "ENTER")
		{
			ans += gomgom.size();
			gomgom.clear();
		}
		else
		{
			gomgom.insert(str);
		}
	}
	if (!gomgom.empty()) ans += gomgom.size();
	cout << ans;
	
	return 0;
}