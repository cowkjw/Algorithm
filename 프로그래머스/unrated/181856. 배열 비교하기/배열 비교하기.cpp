#include <string>
#include <vector>
#include <numeric>
using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int sum1 = accumulate(arr1.begin(),arr1.end(),0);
    int sum2 = accumulate(arr2.begin(),arr2.end(),0);
    if(arr1.size()==arr2.size())
    {
        return (sum1 >= sum2) ? (sum1==sum2 ? 0 : 1) : -1;
    }
    
    return arr1.size()>arr2.size() ? 1 : -1;
}