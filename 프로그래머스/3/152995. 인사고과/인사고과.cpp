#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Info
{
    int work;
    int person;
};

bool cmp(pair<Info,int>& a, pair<Info,int>& b)
{
    if (a.first.work == b.first.work)
        return a.first.person < b.first.person; // 동료 평가 점수는 오름차순 정렬
    return a.first.work > b.first.work; // 근무 태도 점수는 내림차순 정렬
}

bool cmp2(pair<Info,int>& a, pair<Info,int>& b)
{
    if(a.first.work+a.first.person == b.first.work+b.first.person) return a.second < b.second;
    return a.first.work+a.first.person > b.first.work+b.first.person;
}

int solution(vector<vector<int>> scores) {
    
	vector<pair<Info,int>> vec;
    pair<int,int> wan ({scores[0][0],scores[0][1]});

	for (int i = 0; i < scores.size(); i++)
	{
		vec.push_back({{scores[i][0],scores[i][1]},i});
	}
    
	sort(vec.begin(), vec.end(), cmp);
    
    int p = vec[0].first.person;
    int w = vec[0].first.work;
    
	for (int i = 0; i < vec.size(); i++)
	{
        if( p > vec[i].first.person)
        {
            vec[i].first.work = -1;
            vec[i].first.person = -1;
            
            if(wan.first<w&&wan.second < p) 
            {
                return -1; // 완호 인센티브 X
            }
            continue;
        }
        p = max(p,vec[i].first.person);
        w = vec[i].first.work;
	}
    
	sort(vec.begin(), vec.end(), cmp2);
    
    for(int i =0 ;i<vec.size();i++)
    {
        if(vec[i].second == 0) return i+1;
    }
}