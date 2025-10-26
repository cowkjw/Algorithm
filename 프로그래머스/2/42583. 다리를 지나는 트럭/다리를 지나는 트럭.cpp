#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int idx = 0;
    int sum = 0;
    while(true)
    {
        answer++;
        if(q.size() == bridge_length)
        {
            sum-=q.front();
            q.pop();
        }
        
        if(idx<truck_weights.size()&& sum + truck_weights[idx]<=weight)
        {
            q.push(truck_weights[idx]);
            sum+=truck_weights[idx++];
        }
        else
        {
            q.push(0);
        }
        
        if(idx == truck_weights.size()&& sum == 0)
        {
            break;
        }
    }
    return answer;
}