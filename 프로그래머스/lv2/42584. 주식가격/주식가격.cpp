#include <string>
#include <vector>
#include <stack>

using namespace std;
// 스택안의 가격이 넣을 가격보다 작다면 안에 가격 꺼내고 넣을 가격 count해서 vector에 push
// 자신과 같거나 크다면 그대로 넣기
// 다 넣었으면 그대로 빼기 
// 1
// 2 /3 2 
// 2 2 3 

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
    int size = prices.size();
    
    for(int i = 0;i<size;i++)
    {
       
        for(int j = i+1;j<size;j++)
        {
            answer[i]++;
            if(prices[i]>prices[j])
                break;
            
        }
    }
    
   
    
    return answer;
}