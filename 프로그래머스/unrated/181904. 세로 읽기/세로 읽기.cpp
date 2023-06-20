#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    vector<vector<char>> v(my_string.size()/m,vector<char>(m));
    int idx = 0;
    int cnt = 0;
    for(const auto& ch : my_string)
    {
         if(cnt == m)
        {
            cnt = 0;
            idx++;
        }
        v[idx][cnt++] = ch;
    }
    
    for(const auto& arr : v)
    {
        answer+=arr[c-1];
    }
    return answer;
}