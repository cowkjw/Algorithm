#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int parent[101];

int Find(int a)
{
    if(parent[a]==a) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a,int b)
{
    a = Find(a);
    b = Find(b);
    if(a!=b)
    {
        parent[a] = b;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(),costs.end(),[&](const vector<int>& a, const vector<int>& b)
    {
       return a[2]<b[2]; 
    });
    
    for(int i = 1;i<=n;i++)
    {
        parent[i] = i;
    }
    
    for(const auto& cost : costs)
    {
        int u = cost[0], v = cost[1];
        
        if(Find(u)!=Find(v))
        {
            Union(u,v);
            answer+=cost[2];
        }
    }
    

    return answer;
}