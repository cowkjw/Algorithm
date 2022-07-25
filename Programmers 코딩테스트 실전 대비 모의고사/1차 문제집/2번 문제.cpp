#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> ma;

    int size = discount.size() - 9;

    for (int i = 0; i < want.size(); i++)
    {
        ma[want[i]] = number[i];
    }

    for (int i = 0; i < size; i++)
    {
        unordered_map<string, int> temp = ma;
        for (int j = i; j < (10 + i); j++)
        {
            auto it = temp.find(discount[j]);
            if (it != temp.end())
            {
                temp[discount[j]]--;
            }

            if (temp[discount[j]] == 0)
            {
                temp.erase(discount[j]);
            }
        }
        if (temp.empty())
        {
            answer++;
        }
    }


    return answer;
}