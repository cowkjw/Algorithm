#include <string>
#include <vector>
#include<unordered_map> 

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> mp;

    for (auto parti : participant)
    {
        mp[parti]++;
    }

    for (auto com : completion)
    {
        mp[com]--;
    }

    for (auto fail : mp)
    {
        if (fail.second > 0)
        {
            answer = fail.first;
            break;
        }
    }


    return answer;
}
