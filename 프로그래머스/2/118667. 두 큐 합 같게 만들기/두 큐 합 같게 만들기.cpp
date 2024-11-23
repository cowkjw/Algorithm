#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long long q1Sum = accumulate(queue1.begin(), queue1.end(), 0L);
    long long q2Sum = accumulate(queue2.begin(), queue2.end(), 0L);
    
    int q1Start = 0, q2Start = 0;
    int maxMoves = (queue1.size() + queue2.size()) * 2; // 전체 길이 기반으로 계산
    
    while (answer <= maxMoves) {
        if (q1Sum == q2Sum) return answer;
        
        if (q1Sum > q2Sum) {
            q1Sum -= queue1[q1Start];
            q2Sum += queue1[q1Start];
            queue2.push_back(queue1[q1Start]);
            q1Start++;
        } else {
            q2Sum -= queue2[q2Start];
            q1Sum += queue2[q2Start];
            queue1.push_back(queue2[q2Start]);
            q2Start++;
        }
        
        answer++;
    }
    return -1;
}
