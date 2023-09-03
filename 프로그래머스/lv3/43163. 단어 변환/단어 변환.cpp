#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer = 987654321;
int Size;
int vis[51];
vector<string> v;
bool Check(string a, string b)
{
    int cnt = 0;
    for(int i = 0;i<a.size();i++)
        if(a[i]==b[i]) cnt++;
    return (cnt == a.size()-1||cnt==a.size());
}
           
void go(string target,string a,int cnt)
{
    if(target == a)
    {
        answer = min(cnt,answer);
        return;
    }
    
    for(int i = 0;i<Size;i++)
    {
        if(vis[i]) continue;
        if(Check(a,v[i]))
        {
            vis[i] = 1;
            go(target,v[i],cnt+1);
            vis[i]=0;
        }
    }
    return;
}
int solution(string begin, string target, vector<string> words) {

    if(find(words.begin(),words.end(),target)==words.end()) 
        return 0;
    Size = words.size();
    v = words;
    go(target,begin,0);
   return answer;
}