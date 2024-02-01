#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int maxHealth = health; // 최대 체력
    int castTime = bandage[0],rPerSec = bandage[1],addRec = bandage[2]; // 시전시간 초당 회복량 추가 회복량
    int successe = 0,curTime = 0,successeTime = 0,idx = 0;
    
    while(idx<attacks.size())
    {
        vector<int> attack = attacks[idx];
        curTime++;
        
        if(curTime == attack[0])
        {
            health-=attack[1];
            if(health<=0) return -1;
            successe = 0;
            idx++;
        }
        else
        {
            successe++;
            
            if(successe%castTime==0)
            {
                health = min(maxHealth,health+addRec+rPerSec);
                successe = 0;
            }
            else health = min(rPerSec+health,maxHealth);
        }
    }
    answer = health <= 0 ? -1 : health;
    return answer;
}