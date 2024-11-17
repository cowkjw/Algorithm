#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

struct Comp
{
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) const
    {
        if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b); // 소요 시간 기준 오름차순
        if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b); // 요청 시점 기준 오름차순
        return get<2>(a) > get<2>(b); // 작업 ID 기준 오름차순
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Comp> pq; // 대기 큐

    int curTime = 0;        // 현재 시간
    int totalTime = 0;      // 총 대기 시간
    int idx = 0;            // jobs 배열에서 작업 인덱스

    vector<pair<int, int>> vecTemp;
    
    // 요청 시점과 작업 인덱스를 pair로 묶어서 정렬
    for (int i = 0; i < jobs.size(); i++) 
    {
        vecTemp.push_back({jobs[i][0], i});
    }
    sort(vecTemp.begin(), vecTemp.end());

    // 작업 처리
    while (idx < jobs.size() || !pq.empty()) 
    {
        // 현재 시간보다 요청 시점이 빠른 작업을 대기 큐에 넣음
        while (idx < jobs.size() && vecTemp[idx].first <= curTime) 
        {
            pq.push({jobs[vecTemp[idx].second][0], jobs[vecTemp[idx].second][1], vecTemp[idx].second});
            idx++;
        }

        // 대기 큐에 작업이 있으면, 큐에서 작업을 꺼내서 처리
        if (!pq.empty()) 
        {
            auto cur = pq.top();
            pq.pop();
            curTime += get<1>(cur); // 소요 시간만큼 현재 시간 갱신
            totalTime += (curTime - get<0>(cur)); // 대기 시간 추가
        } 
        else 
        {
            // 대기 큐에 작업이 없으면, 다음 요청 시점으로 이동
            if (idx < jobs.size()) 
            {
                curTime = vecTemp[idx].first;
            }
        }
    }

    // 평균 대기 시간 계산
    answer = totalTime / jobs.size();
    return answer;
}
