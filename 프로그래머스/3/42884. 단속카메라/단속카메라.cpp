#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

bool comp(vector<int>& a,vector<int>& b)
{
    return a[1]<b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(),routes.end(),comp);
    int pos = routes[0][1];
    for(int i = 1;i<routes.size();i++)
    {
        if(routes[i][0]<=pos&&routes[i][1]>=pos) continue;
        else pos = routes[i][1],answer++;
    }
    
    return answer;
}