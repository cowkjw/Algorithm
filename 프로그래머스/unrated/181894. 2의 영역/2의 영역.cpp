#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {

    vector<int> answer;
    int s = -1, e = -1;
    
    auto it = find(arr.begin(), arr.end(), 2);
   if (it != arr.end()) 
   {
        s = distance(arr.begin(), it);
        e = s;
        while ((it = find(it + 1, arr.end(), 2)) != arr.end()) 
        {
            e = max(e, (int)distance(arr.begin(), it));
        }
        answer.assign(arr.begin() + s, arr.begin() + e + 1);
    }
    else 
    {
        answer.push_back(-1);
    }
    
    return answer;
}