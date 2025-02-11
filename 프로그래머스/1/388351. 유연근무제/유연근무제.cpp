#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
 
    for(int i = 0;i<timelogs.size();i++)
    {
        vector<int> timeLog = timelogs[i];
        int hour = schedules[i]/100 + ((schedules[i] % 100) + 10)/60;
        int min = ((schedules[i] % 100) + 10)%60;
        int sc = hour*100 + min;
        bool reward = true;
        
        auto it = timeLog.begin();
        while((it = find_if(it,timeLog.end(),[&](int t){
                    return t>sc;})) != timeLog.end())
        { if(it!=timeLog.end())
        {
            int day = (startday + (it - timeLog.begin()))%7;
            if(day != 6 && day != 0)
            {
                reward = false;
                break;
            }
        }
            ++it;
        }
        if(reward) answer++;
    }
    
    return answer;
}