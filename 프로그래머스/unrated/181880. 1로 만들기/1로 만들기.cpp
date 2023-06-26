#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    for(auto& num : num_list)
    {
        while(num!=1)
        {
            if(num%2==0)
            {
                num/=2;
            }
            else
            {
                num--;
                num/=2;
            }
            answer++;
        }
    }
    return answer;
}