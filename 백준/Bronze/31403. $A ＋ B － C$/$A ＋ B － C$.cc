#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> vec(3, 0);
	for (int i = 0; i < 3; i++)
	{
		cin >> vec[i];
	}
	cout << vec[0] + vec[1] - vec[2]<<"\n";
	cout << stoi(to_string(vec[0]) + to_string(vec[1])) - vec[2];
	return 0;
}

