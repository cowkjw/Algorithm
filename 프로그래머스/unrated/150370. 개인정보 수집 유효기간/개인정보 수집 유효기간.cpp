#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;
	vector<int> todayInt{ stoi(today.substr(0,4)),stoi(today.substr(5,2)),
						 stoi(today.substr(8,2)) };
	map<string, int> m;
	for (const auto& term : terms)
	{
		m[term.substr(0, 1)] = stoi(term.substr(2));
	}
    int todayTotal = (todayInt[0] * 12 * 28) + (todayInt[1] * 28) + todayInt[2];

	for (int i = 0; i < privacies.size(); i++)
	{
		int term = m[privacies[i].substr(11)];
		int year = stoi(privacies[i].substr(0, 4));
		int month = stoi(privacies[i].substr(5, 2));
		int day = stoi(privacies[i].substr(8, 2));
        
       	int total = (year * 12 * 28) + (month * 28) + (day+term*28);
		
		if(total<=todayTotal) answer.push_back(i + 1);
    }
	return answer;
}