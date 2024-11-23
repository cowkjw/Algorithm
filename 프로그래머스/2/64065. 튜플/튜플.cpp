#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <map>
using namespace std;
bool comp(const pair<int,int>& a,const pair<int,int>& b)
{
    return a.second>b.second;
}
vector<int> solution(string s) {
   vector<int> answer;
    regex regex("\\d+");
    
    sregex_iterator begin(s.begin(), s.end(), regex);
    sregex_iterator end;
    map<int,int> m;
    for (auto it = begin; it != end; ++it) 
    {
        m[stoi(it->str())]++; 
    }
    
    vector<pair<int,int>> vecTemp(m.begin(),m.end());
    sort(vecTemp.begin(),vecTemp.end(),comp);
    for(const auto& i : vecTemp)
    {
        answer.push_back(i.first);
    }
    return answer;
}