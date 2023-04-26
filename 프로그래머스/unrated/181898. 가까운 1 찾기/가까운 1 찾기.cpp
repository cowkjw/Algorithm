#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int idx) {
    int answer = -1;
    for(;idx<arr.size();idx++)
    {
        if(arr[idx]==1)
        {
            return idx;
        }
    }
    return answer;
}