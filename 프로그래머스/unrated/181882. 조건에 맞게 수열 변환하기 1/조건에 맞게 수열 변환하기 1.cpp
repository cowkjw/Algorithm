#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    for(auto& ele : arr)
    {
        if(ele>=50&&ele%2==0)
        {
            ele /=2;
        }
        else if(ele<50&&ele%2!=0)
        {
            ele*=2;
        }
    }
    return arr;
}