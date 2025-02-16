#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    

    queue<int> serverEndTimes;  // 서버 종료 시간을 추적하는 큐

    // 각 시간대에 대해 필요한 서버 수 계산
    for (int i = 0; i < players.size(); i++) 
    {
        int currentPlayers = players[i];

        // 종료된 서버들 처리 (현재 시간에서 k시간이 지난 서버들)
        while (!serverEndTimes.empty() && serverEndTimes.front() <i) 
        {
            serverEndTimes.pop();  // 종료된 서버 제거
        }

        // 현재 시간에 필요한 서버 수 계산
       int neededServers = (currentPlayers + m - 1) / m;    // 필요한 서버 개수 (올림 처리)

        // 필요한 서버 수가 더 많으면 새로 서버 증설
        while (serverEndTimes.size() < neededServers)
        {
            serverEndTimes.push(i + k);  // 서버는 k시간 후에 종료되므로 종료 시간을 기록
            answer++;  // 서버 증설 횟수 증가
        }
    }

    return answer;
}