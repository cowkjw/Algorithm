#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer(arr.begin(),arr.end());
    int i = 1;
    while(pow(2,i++)<arr.size())
    for(int j = 0;j<pow(2,i)-arr.size();j++)
    {
        answer.push_back(0);
    }
    return answer;
}