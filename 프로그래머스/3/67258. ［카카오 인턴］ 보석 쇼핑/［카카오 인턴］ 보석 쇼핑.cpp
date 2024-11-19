#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2,1000001);
    unordered_set<string> uniGem;
    for(const auto& gem : gems)
    {
        uniGem.insert(gem);
    }
    
    int left = 0,right =0; 
    
    int dis = 1000000;
    unordered_map<string,int> countGem;
    while(right<gems.size())
    {
        countGem[gems[right]]++;
        // right로 구간을 늘렸고, left~right까지에서 left를 다시 늘려주면서
        // 이전의 left 구간의 보석들의 개수를 -- 해주기 위함
      while(uniGem.size()==countGem.size()) 
        {
            int tempDis = right-left;
            if(dis> tempDis)
            {
                dis = tempDis;
                answer[0] = left + 1;  
                answer[1] = right + 1; 
            }
            countGem[gems[left]]--;
            
            if(countGem[gems[left]]==0)
            {
                countGem.erase(gems[left]);
            }
            left++;
        }
        right++; // right는 계속 구간을 늘려줌
    }
    return answer;
}