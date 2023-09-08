#include <string>
#include <vector>

using namespace std;

vector<string> v{ "A","E","I","O","U" };
int answer,cnt;
void dfs(string target,string now)
{
    if(target == now) answer = cnt;
    if(now.size()>5) return;
    cnt++;
    for(int i = 0;i<v.size();i++)
    {
       dfs(target,now+v[i]);
    }
    return;
}
int solution(string word) {
    dfs(word,"");
	return answer;
}