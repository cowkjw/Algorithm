#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

string arr[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };


long long solution(string numbers) {
	long long answer = 0;
	string str;

	
		for (int i = 0; i < 10; i++)
		{
			while(numbers.find(arr[i]) != -1)
			{
				numbers.replace(numbers.begin()+numbers.find(arr[i]), numbers.begin() + numbers.find(arr[i]) + arr[i].size(), to_string(i));
			}
        }
	
	return stoll(numbers);;
}