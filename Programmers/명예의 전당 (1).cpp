#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int> pq;
    for (int day = 0; day < score.size(); day++)
    {
        if (day < k)
            pq.push(-score[day]);
        else if (score[day] > (-pq.top()))
        {
            pq.pop();
            pq.push(-score[day]);
        }

        answer.push_back(-pq.top());

    }
    return answer;
}