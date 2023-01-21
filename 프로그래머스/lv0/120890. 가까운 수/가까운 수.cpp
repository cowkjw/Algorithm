#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
	 sort(array.begin(),array.end());
    int answer = array[0];
   
	for_each(array.begin(), array.end(), [&](int& item)
		{
			abs(answer - n) > abs(item - n) ? abs(answer - n) == abs(item - n) ? answer > item ? answer = item : answer = answer:
				answer = item : answer = answer;
		});

	return answer;
}