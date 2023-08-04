#include <string>
#include <vector>

using namespace std;

int arr[26];
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(const auto& skill_tree : skill_trees)
    {
        
        fill(arr,arr+26,-1);
        for(int i = 0;i<skill_tree.size();i++)
        {
            arr[skill_tree[i]-'A'] = i;
        }
        bool flag = true;
        for(int j = 0; j<skill.size()-1;j++)
        {
            
            if (arr[skill[j + 1] - 'A'] != -1)
            {
                if ((arr[skill[j] - 'A'] >= arr[skill[j + 1] - 'A']))
                {
                    flag = false;
                    break;
                }
                else
                {
                    if(arr[skill[j] - 'A']==-1)
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag) answer++;
    }
    return answer;
}