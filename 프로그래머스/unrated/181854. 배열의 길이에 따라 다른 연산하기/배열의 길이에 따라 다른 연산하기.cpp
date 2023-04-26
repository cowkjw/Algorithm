#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    bool odd = arr.size()%2!=0;
    if(odd)
    {
        for(int i = 0;i<arr.size();i+=2)
        {
            arr[i]+=n;
        }
    }
    else
    {
        for(int i = 1;i<arr.size();i+=2)
        {
            arr[i]+=n;
        }
    }
    return arr;
}