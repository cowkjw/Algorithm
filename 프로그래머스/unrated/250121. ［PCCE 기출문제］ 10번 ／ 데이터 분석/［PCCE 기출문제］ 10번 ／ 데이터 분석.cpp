#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void SortData(vector<vector<int>>& answer,string sort_by)
{
     if(sort_by == "code")
        {
            sort(answer.begin(),answer.end(),[&](vector<int>& a,vector<int>& b)
                 {
                     return a[0]<b[0];
                 });
        }
        else if(sort_by == "date")
        {
               sort(answer.begin(),answer.end(),[&](vector<int>& a,vector<int>& b)
                 {
                     return a[1]<b[1];
                 });
        }
        else if(sort_by == "maximum")
        {
               sort(answer.begin(),answer.end(),[&](vector<int>& a,vector<int>& b)
                 {
                     return a[2]<b[2];
                 });
        }
        else 
        {
               sort(answer.begin(),answer.end(),[&](vector<int>& a,vector<int>& b)
                 {
                     return a[3]<b[3];
                 });
        }
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    for(auto& d : data)
    {
        int code = d[0];
        int date = d[1];
        int maximum = d[2];
        int remain = d[3];
        if(ext == "code")
        {
            if(val_ext>code) answer.push_back(d);
        }
        else if(ext == "date")
        {
            if(val_ext>date) answer.push_back(d);
        }
        else if(ext == "maximum")
        {
            if(val_ext>maximum) answer.push_back(d);
        }
        else 
        {
            if(val_ext>remain) answer.push_back(d);
        }
    }
    SortData(answer,sort_by);
    return answer;
}