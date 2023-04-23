#include <string>
#include <vector>
#include <numeric>
using namespace std;

long long solution(vector<int> num_list) {
    return num_list.size()<=10?
        accumulate(num_list.begin(), num_list.end(), 1, multiplies<long long>()):
        accumulate(num_list.begin(), num_list.end(), 0);
}