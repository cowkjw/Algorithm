#include <string>
#include <vector>
#include <map>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
	vector<int> answer = emergency;
	map<int, int> m;

	sort(emergency.rbegin(), emergency.rend());

	for (int i = 0; i < emergency.size(); i++)
	{
		m[emergency[i]] = i + 1;
	}

	for (int i = 0; i < answer.size(); i++)
	{
		answer[i] = m[answer[i]];
	}

	return answer;
}