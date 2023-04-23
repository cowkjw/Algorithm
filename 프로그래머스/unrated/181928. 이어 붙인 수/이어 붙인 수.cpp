#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    string even,odd;
    for(const auto num : num_list)
    {
        if(num%2==0)
        {
            even+=to_string(num);
        }
        else
        {
            odd+=to_string(num);
        }
    }
    return stoi(odd)+stoi(even);
}