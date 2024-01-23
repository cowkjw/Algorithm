#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string,int> m; // 이름,선물 지수
    map<string,map<string,int>> m2; // 이름 , 주고 받은 사람, 준 개수

    for(const auto& g : gifts)
    {
        string a,b,tmp; // 주는, 받는
        for(int i = 0;i<g.size();i++)
        {
            if(g[i]!=' ')
            {
                tmp+=g[i];
            }
            else
            {
                a = tmp;
                tmp.clear();
            }
        }
        b = tmp;
        m[a]++;
        m[b]--;
        m2[a][b]++;
        m2[b][a]--;
    }
    
    for(const auto& i : m2) // 주는 애
    {
        int cnt = 0;
        // TODO
        // 1. 주고 받았는지 확인
        // 2. 누가 더 많이 줬는지 확인
        // 3. 두 사람이 기록이 없거나 주고 받은게 같은지 확인
        //    - 그렇다면 선물 지수가 더 큰 사람이 선물받기
        for(const auto& f: friends) // 받은 애
        {
            if(i.second.find(f) == m2[i.first].end()||
              m2[i.first][f] == m2[f][i.first]) // 주고 받은 기록이 없음.
            {
               if(m[i.first] > m[f])
               {
                   cnt++; // 지수 더 큰 경우 선물 받기
               }
            }
            else if(i.second.find(f) != m2[i.first].end()) // 주고 받았고
            {
                if(m2[i.first][f] > m2[f][i.first])
                {
                    cnt++; // 준게 더 많음
                }
            }
        }
        answer = max(cnt,answer);
    }
    return answer;
}