#include <iostream>
#include <queue>
#include <unordered_map>
#include<deque>
#include <list>
#include<numeric>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> vec(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> vec[i];
	}
	vector<int> numbers;
	transform(vec.begin(), vec.end(), back_inserter(numbers), [](const string& str) 
		{
		return isdigit(str[0]) ? stoi(str) : 0;
		});
	int maxNum = *max_element(numbers.begin(), numbers.end());
	int dist = find(vec.begin(), vec.end(), to_string(maxNum)) - vec.begin();
	int nextNum = maxNum + (3-dist);

	cout << (nextNum % 3 == 0 && nextNum % 5 == 0 ? "FizzBuzz" :
		(nextNum % 5 == 0 ? "Buzz" :
			(nextNum % 3 == 0 ? "Fizz" : to_string(nextNum))));
	return 0;
}

