#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long CalculatingTime(const int level, const vector<int>& diffs, const vector<int>& times)
{
    long long totalTime(0);
    long long prevTime (0);
    
    for(int i = 0 ; i<diffs.size(); i++)
    {
        if(level < diffs[i])
        {
            // (현재 + 이전 시간) * 횟수 + 현재  
            totalTime += (times[i] + prevTime) * (diffs[i] - level) + times[i];
        }
        else
        {
            totalTime += times[i];
        }
        prevTime = times[i];
    }
    
    return totalTime;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int left(1);
    int right(100000);
    int answer(0);
    //반씩 쪼개서 계산??

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        long long totalTime = CalculatingTime(mid,diffs,times);
        
        if (totalTime <= limit) 
        {
            answer = mid;
            right = mid - 1; // 타겟이 중간값보다 작으면 왼쪽 부분 탐색
        } 
        else 
        {
           left = mid + 1; // 타겟이 중간값보다 크면 오른쪽 부분 탐색
        }
    }
    return answer;
}