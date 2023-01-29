#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    sort(stages.begin(),stages.end());
    int size = stages.size(); // 인원 수
    vector<pair<int,double>> v;
    for(int i = 1;i<=N;i++)
    {
        int challenger = count(stages.begin(),stages.end(),i);
        
        if(challenger==0)
        {
             v.push_back({i,0});
        }
        else
        {
            v.push_back({i,(double)challenger/size});
        }
        
        size -=challenger;
    } 
    sort(v.begin(),v.end(),[](pair<int,double>& a, pair<int,double>& b){
        
        if(a.second==b.second)
            return a.first<b.first;
        return a.second>b.second;
    });
    for(const auto& item : v)
    {
        answer.push_back(item.first);
    }

    return answer;
}