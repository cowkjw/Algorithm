#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    if (k >= enemy.size()) return (int)enemy.size();
    priority_queue<int> pq;
    int sum = 0;
    for (int i = 0; i < enemy.size(); i++)
    {
        pq.push(-enemy[i]); // min Heap
        while (pq.size() > k) // 무적권 초과
        {
            sum+= -pq.top(); // 작은 수부터  더함
            pq.pop();
        }
        if (sum > n) return i; // HP 다 씀
    }
}