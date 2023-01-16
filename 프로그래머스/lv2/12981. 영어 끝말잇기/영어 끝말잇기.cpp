#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer{0,0};
    set<string> se;
    int cnt = 0;
    int rot = 0;
    
    for(int i = 0;i<words.size();i++)
    {
        if((i)%n==0)
        {
            rot++;
        }
        if(i!=0&&words[i-1].back()!=words[i].front())
        {
            
            answer[0] = i%n==0? 1 : (i % n)+1;
            answer[1] = rot;
            break;
        }
        else if(se.find(words[i])!=se.end())
        {
           answer[0] = i%n==0? 1 : (i % n)+1;
            answer[1] = rot;
            break;
        }
        else
        {
            se.insert(words[i]);
        }
    }

    return answer;
}