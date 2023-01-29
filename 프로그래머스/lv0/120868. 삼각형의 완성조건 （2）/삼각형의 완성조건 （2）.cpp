#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    auto minNum = *min_element(sides.begin(), sides.end());
    auto maxNum = *max_element(sides.begin(), sides.end());
 
    
    return (minNum+maxNum) - (maxNum-minNum) -1;
}