#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(const auto& target : targets)
    {
        int idx = 0;
        for(const auto& ch : target)
        {
            unsigned long cnt = 101;
            for(const auto& key : keymap)
            {
                if(key.find(ch)!=-1)
                    cnt = min(cnt,key.find(ch)+1);
            }
            
            if(cnt==101)
            {
                idx = -1;
                break;
            }
            else
                idx+=cnt;
        }
        answer.push_back(idx);
    }
    return answer;
}