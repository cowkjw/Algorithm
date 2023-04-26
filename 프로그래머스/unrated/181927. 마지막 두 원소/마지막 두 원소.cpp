#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    auto size = num_list.size();
    int a = num_list[size-1];
    int b = num_list[size-2];
    a>b ? num_list.push_back(a-b) :num_list.push_back(a*2);
    return num_list;
}