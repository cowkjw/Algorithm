#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(distance);
    sort(rocks.begin(),rocks.end());
    int s = 1,e = distance+1;
    while(s<=e)
    {
        int mid = (s+e) / 2; // 제거하는 거리
        int pRock = 0;
        int cnt = 0;
        for(auto rock : rocks)
        {
            if(rock-pRock<mid) // 제거할 수 있는 거리보다 크다는거니까
            {
                // 제거 가능
                cnt++;
            }
            // 새로 더 큰 이전 돌을 찾아야함 차이가 너무 컸다는 뜻
            else  pRock = rock;
        }
        if(cnt<=n)
        {
            s = mid+1; // 최소 중 최대
            answer = mid;
        }
        else
        {
            e = mid-1; // 너무 큼
        }
    }
    // 2 11 14 17 21 // 2 9  3 11
    // 2 9 3 3 4
    return answer;
}