#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long CalculatingTime(const int level, const vector<int>& diffs, const vector<int>& times)
{
    long long totalTime(0);
    long long prevTime (0);
    // 레벨이 낮은 경우 cur * 2  + prev * (diff - level) 만큼 시간 사용
    
    for(int i = 0 ; i<diffs.size(); i++)
    {
        if(level < diffs[i])
        {
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
    int left = 1;
    int right = 100000;
    int answer = right;
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