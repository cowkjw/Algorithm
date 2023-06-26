#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int arr[31];
int solution(vector<string> strArr) {
    int answer = 0;
    for(const auto& str : strArr)
    {
        arr[str.size()]++;
    }
    
    answer = *max_element(arr,arr+31);
    return answer;
}