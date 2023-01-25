#include <string>
#include <vector>

using namespace std;


vector<int> solution(int num, int total) {
    vector<int> answer;
    
    int start = 0;
    
    while(true)
    {
        int sum = 0;
        for(int i = start;i<start + num;i++)
        {
            sum+=i;
        }
        if(sum>total)
        {
            start--;
        }
        else if(sum<total)
        {
            start++;
        }
        else
        {
            break;
        }
    }
    for(int i = start;i<start+num;i++)
    {
        answer.push_back(i);
    }
    return answer;
}