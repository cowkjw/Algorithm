#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool comp1(pair<string,int> a,pair<string,int> b)
{
    return a.second>b.second;
}
bool comp2(pair<int,int> a,pair<int,int> b)
{
    return a.second>b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> m1;//장르
    map<string,map<int,int>> m2;
    
    for(int i = 0;i<genres.size();i++)
    {
        string genre = genres[i];
        int play = plays[i];
        m1[genre]+=play;
        m2[genre].insert({i,play});
    }
    vector<pair<string,int>> v(m1.begin(),m1.end());
    sort(v.begin(),v.end(),comp1);
    
    for(auto genre : v)
    {
        vector<pair<int,int>> temp(m2[genre.first].begin(),
                                   m2[genre.first].end());
        sort(temp.begin(),temp.end(),comp2);
        int size = temp.size()>=2 ? 2 : 1;
        for(int i = 0;i<size;i++)
        {
            answer.push_back(temp[i].first);
        }
    }    
    return answer;
}