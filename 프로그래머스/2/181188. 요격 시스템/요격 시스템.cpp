#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    return a[1]<b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(),targets.end(),comp);
    int end = 0;
    
    for(int i = 0;i<targets.size();i++)
    {
        if(end<=targets[i][0])
        {
            answer++;
            end = targets[i][1];
        }
    }

    return answer;
}