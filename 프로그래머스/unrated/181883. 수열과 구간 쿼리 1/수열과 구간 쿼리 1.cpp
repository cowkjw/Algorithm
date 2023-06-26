#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer = arr;
    
    for(const auto& query : queries)
    {
        int s = query[0];
        int e = query[1];
        
        for_each(answer.begin()+s,answer.begin()+e+1,[&](int& num)
                 {   
                     num+=1;
                 });
    }
    return answer;
}