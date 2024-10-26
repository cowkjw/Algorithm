#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define INF 987654321
#define MOD 1000000
using namespace std;

string str1, str2;

bool Func()
{
    while (str2.length() > str1.length())
    {
        if (str2.back() == 'A')
        {
            str2.pop_back();
        }
        else if (str2.back() == 'B')
        {
            str2.pop_back();
            reverse(str2.begin(), str2.end());
        }
    }
    return str1 == str2;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> str1 >> str2;

	cout<<Func();
	return 0;
}