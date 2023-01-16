#include <string>
#include <vector>
#include <unordered_map>
#include <map>


using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
   unordered_map<string,int> m;
    
    for(int i = 0;i<want.size();i++)
    {
        m[want[i]] = number[i];
    }
    
    int size = discount.size()-9; // 인덱스 범위 생각
    
    for(int i = 0;i<size;i++)
    {
        unordered_map<string,int> temp = m; // 복사
        
        for(int j = i;j<10+i;j++)
        {
            if(temp.find(discount[j])!=temp.end())
            {
                temp[discount[j]]--;
            }
               
            if(temp[discount[j]]==0)
            {
                temp.erase(discount[j]);
            }       
            
            if(temp.empty())
            {
                answer++;
            }
               
        }
    
    }
    
    
    return answer;
}