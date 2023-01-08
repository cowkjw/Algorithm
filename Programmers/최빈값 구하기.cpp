#include <string>
#include <vector>
#include<algorithm>

using namespace std;
vector<int> vec(1001);
int solution(vector<int> array) {

	for (const auto& num : array)
	{
		vec[num]++;
	}

	auto it = max_element(vec.begin(), vec.end());

	if (*max_element(it + 1, vec.end()) == *it)
		return -1;
	else return it - vec.begin();


}