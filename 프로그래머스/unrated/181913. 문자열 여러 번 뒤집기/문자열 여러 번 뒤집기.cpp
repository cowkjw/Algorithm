#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    for(const auto query : queries)
    {
        reverse(my_string.begin() + query[0], my_string.begin() + query[1]+1);
    }
    
    return my_string;
}