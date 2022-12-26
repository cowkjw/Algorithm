#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int>pq(works.begin(), works.end());

    while (n--)
    {
        auto hWork = pq.top();
        pq.pop();
        if (hWork > 0)
            hWork--;
        pq.push(hWork);
    }

    while (!pq.empty())
    {
        auto temp = pq.top();
        answer += pow(temp, 2);
        pq.pop();
    }
    return answer;
}