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
		
	set<string> chongchong;
	chongchong.insert("ChongChong");
	while (n--)
	{
		string name,name1;
		cin >> name>>name1;

		if (chongchong.find(name) != chongchong.end())
		{
			chongchong.insert(name1);
		}
		else if(chongchong.find(name1) != chongchong.end())
		{
			chongchong.insert(name);
		}
	}
	cout << (ans += chongchong.size());
	return 0;
}