#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(vector<int> arr, int k) {

    for(auto& num : arr)
    {
        if(k%2==0)
        {
            num+=k;
        }
        else
        {
            num*=k;
        }
    }
    return arr;
}