#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    for (int i = 0; i < bridge_length; i++) q.push(-1);

    int cur = 0;
    int i = 0;
    while (1)
    {
        if (q.front() != -1) cur -= q.front();
         if (cur + truck_weights[i] <= weight)
        {
            q.push(truck_weights[i]);
            cur += truck_weights[i];
            i++;
        }
        else
        {
            q.push(-1);
        }
        answer++;
        q.pop();
        if (i >= truck_weights.size()) break;
    }
    while (!q.empty())
    {
        answer++;
        q.pop();
    }
    return answer;
}