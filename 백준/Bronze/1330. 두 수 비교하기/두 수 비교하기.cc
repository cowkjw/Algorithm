#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int a, b;
	cin >> a >> b;
	cout << string(a == b ? "==" : (a > b ? ">" : "<"));
    return 0;
}